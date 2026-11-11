#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
typedef long long ll;
int n,aa[N];
char s[N];
ll a[N],b[N];
char c[N],d[N]; 
vector<pair<ll,char>> a1,b1;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d %c",&aa[i],&s[i]);
	ll cnt=0;
	for(int i=1;i<=n;i++){
		cnt+=aa[i];
	}
//	printf("   %d   ",cnt);
	int l1=0,l2=0;
	ll cnt1=0,cnt2=0;
	int i=1,j=1;
	while(cnt1<=cnt/2){
		a[++l1]=aa[i];
		c[l1]=s[i];
		i++;
		cnt1+=a[l1];
	}
//	printf("%d %d %d",a[l1],cnt1,n)
	a[l1]=(ll)a[l1]-cnt1+cnt/2;
	if(a[l1]==0)
		l1--;
	while(cnt2<=cnt/2){
		b[++l2]=aa[n-j+1];
		d[l2]=s[n-j+1];
		j++;
		cnt2+=b[l2];
	}
	b[l2]=b[l2]-cnt2+cnt/2;
	if(b[l2]==0)
		l2--;
//	for(int i=1;i<=l1;i++)
//		printf("**%d **%c\n",a[i],c[i]);
//	for(int i=1;i<=l2;i++)
//		printf("^^%d ^^%c\n",b[i],d[i]);
	bool f=0;
	cnt1=cnt2=0;
	i=j=1;
	ll k=0,ok=0;
	while(k<cnt/2){
		ok=k;
		if(cnt1+a[i]<cnt2+b[j]){
			k=cnt1+a[i];
			cnt1+=a[i];
			f=0;
			i++;
		}
		else{
//			printf("%d\n",k);
			k=cnt2+b[j];
			f=1;
			cnt2+=b[j];
			j++;
		}
		if(f==0){
			b1.push_back({cnt1-ok,d[j]});
			a1.push_back({cnt1-ok,c[i-1]});
		}
		else{
			b1.push_back({cnt2-ok,d[j-1]});
			a1.push_back({cnt2-ok,c[i]});
		}
//		puts("1");
	}
//	printf("%d",(int)a1.size());
	int sz=(int)a1.size();
	ll ans=0;
	for(int i=0;i<=sz-1;i++){
		if(a1[i].second!=b1[i].second)
			ans+=(ll)a1[i].first;
//		printf("%lld ",a1[i].first);
	}
	printf("%lld",ans);
	return 0;
}
