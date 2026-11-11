#include<bits/stdc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f
#define lowbit(x) x&(-x)
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) a*b/__gcd(a,b)
#define pii pair<int,int>
#define first fst
#define second sed
#define dbg() printf("dbg\n")
using namespace std;

const int MAXN=5e5+10;
int a[MAXN];
int n,m;

void spj(){
	int d=a[2]-a[1];
	int tot=0;//count the value of d*0+d*1+d*2+...+d*max{k}
	int cnt=1;
	for(int k=1;k<=n;k++){
		tot+=d*k;
		if(tot<=m)cnt++;
		else break;
	}
	printf("%lld",cnt);
}

bool check(){
	for(int i=2;i<n;i++){
		if(a[i]-a[i-1]!=a[i+1]-a[i])return false;
	}
	return true;
}

void Code(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(check()){spj();return ;}
	int ans=-inf;//in order
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++){
		vector<int> v;
		for(int j=1;j<i;j++)v.push_back(a[i]-a[j]);
		sort(v.begin(),v.end());
		int cnt=1;//when the crystal is a[i],count how many crystals can be the large crystal
		int tot=0;//when the crystal is a[i],count how many times now,the times is array v
		int id=0;//in order,the array v is small to large,it is the id of v
		while(tot<=m and id<v.size()){
			tot+=v[id];id++;
			if(tot<=m)cnt++;
			else break;
		}
		ans=max(ans,cnt);
	}
	printf("%lld",ans);
}

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int t;t=1;
	while(t--)Code();
	return 38&17;
}

