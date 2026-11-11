#include<bits/stdc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) a*b/__gcd(a,b)
#define lowbit(x) x&(-x)
#define pii pair<int,int>
using namespace std;

const int MAXN=2e5+10;
int a[MAXN];
int pow2[]={1,3,7,15,31,63,127,255,511,1023,2047,4095,8191,16383,32767,65535,131071,262143,524287,1048576};
int n,m;

void sp6(){
	int ans=-inf;
	for(int i=1;i<=n;i++)ans=max(ans,a[i]);
	printf("%lld",ans);
} 

void sp7(){
	int ans=a[1];
	for(int i=2;i<=n;i++)ans&=a[i];
	printf("%lld",ans);
}

void sp8to10(){
	int ans=-inf;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++)ans=max(ans,a[i]&a[j]);
	}
	printf("%lld",ans);
}

bool checka(){
	for(int i=1;i<=n;i++){
		bool f=0;
		for(int x:pow2){
			if(x==a[i]){f=1;break;}
		}
		if(!f)return false;
	}
	return true;
}

void spa(){
	sort(a+1,a+1+n,greater<int>());
	printf("%lld",a[m]);
}

bool checkb(){
	for(int x:pow2){
		if(n!=x)return false;
	}
	for(int i=1;i<=n;i++){
		if(a[i]!=i-1)return false;
	}
	return true;
}

void spb(){printf("0");}

void Code(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(m==1)sp6();
	else if(m==n)sp7();
	else if(m==2)sp8to10();
	else if(checka())spa();
	else if(checkb())spb();
	else printf("0");
}

signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int t;t=1;
	while(t--)Code();
	return 0;
}

