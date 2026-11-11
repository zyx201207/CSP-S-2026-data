#include<iostream>
#include<cstdio>
#include<algorithm>
#include<climits>
#include<cstring>
#define ll long long
using namespace std;
const int N=1e6+86;
ll n,d,m,tot=0;
struct T{
	ll num;
	ll id;int ids;
};
ll a[N],ans,fx[N];
bool f=1;
T b[N],c[N];
void fc(ll ds){
//	if(m>=ds) ans++;
	ans=1;
	for(int i=1;i<=n;i++){
		if(m>=ds) ans++;
		else break;
		ds+=(i+1)*d;
	}
	return;
}
bool cmp(T xcf,T lj){
	return xcf.num<lj.num;	
}
bool cmp1(T lss,T xcf){
	return lss.id<xcf.id;	
}
ll cnts,r;
ll ans1;
ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9') {
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+(c-'0');
		c=getchar();
	}
	return x*f;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
//	n=read();m=read();
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		a[i]=read();
//		scanf("%lld",&a[i]);
	}
	stable_sort(a+1,a+1+n);
	d=a[2]-a[1];
	for(int i=1;i<n;i++)if(a[i+1]-a[i]!=d) f=0;
	if(f){
		fc(d);
		cout<<ans;
		return 0;
	}
	if(a[1]==0) tot=1,b[tot].id=0;
	for(int i=1;i<=n;i++){
		if(a[i]!=a[i-1])tot++,b[tot].id=a[i];
		b[tot].num++;
	}
	stable_sort(b+1,b+1+tot,cmp);
	for(int i=1;i<=tot;i++)b[i].ids=i;
	for(int i=1;i<=tot;i++)c[i].id=b[i].id,c[i].num=b[i].num,c[i].ids=b[i].ids;
	stable_sort(c+1,c+1+tot,cmp1);
	for(int i=1;i<=tot;i++) fx[c[i].ids]=i;
	for(int i=tot;i>=1;i--){
		cnts=m;
		ans=b[i].num;
//		cout<<ans<<" ";
		for(int j=fx[b[i].ids]-1;j>=1;j--){
//			printf("%lld:%lld %lld %lld|%lld\n",i,j,b[i].id-c[j].id,c[j].id,cnts);
//			cout<<i<<":"<<j<<" "<<b[i].id-c[j].id;
			if((b[i].id-c[j].id)*c[j].num<=cnts){
				ans+=c[j].num;
				cnts-=(b[i].id-c[j].id)*c[j].num;
			}else if(b[i].id-c[j].id<=cnts){
//				cout<<b[i].id-c[j].id<<" "<< '\n';
				r=(ll)(cnts/(b[i].id-c[j].id));
				ans+=r;
//				cout<<ans<<" ";
				cnts-=r*(b[i].id-c[j].id);
			}else cnts=0;
			if(ans>ans1) ans1=ans;
			if(cnts<=0) break;
		}
	}
	cout<<ans1;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
