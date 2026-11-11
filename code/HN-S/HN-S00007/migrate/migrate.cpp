#include<bits/stdc++.h>
#define int long long
#define rag(i,l,r) for(i=(l);i<=(r);i++)
#define reg(i,r,l) for(i=(r);i>=(l);i--)
#define irag(i,l,r) for(int i=(l);i<=(r);i++)
#define ireg(i,r,l) for(int i=(r);i>=(l);i--)
using namespace std;
template<typename x>x maxx(x a){return a;}
template<typename x,typename y>x maxx(x a,y b){return a<b?b:a;}
template<typename x,typename y,typename...z>x maxx(x a,y b,z...c){return maxx(maxx(a,b),c...);}
template<typename x>x minn(x a){return a;}
template<typename x,typename y>x minn(x a,y b){return a<b?a:b;}
template<typename x,typename y,typename...z>x minn(x a,y b,z...c){return minn(minn(a,b),c...);}
const int TMXO_n=2e6+100;
int c,T,n,d,i,a[TMXO_n],l,r,s,t,ans,can[TMXO_n],cnt;bool v[TMXO_n];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		memset(v,false,sizeof(v)),ans=cnt=0;
		cin>>n>>d;
		rag(i,1,n){
			cin>>a[i];
			if(i>2&&a[i]-a[i-2]<=d)v[i]=true,can[++cnt]=i;
			if(i>3&&a[i]-a[i-3]<=d)cnt--;
		}
		rag(i,1,cnt){
			l=s=can[i]-2,r=t=can[i];
			while(!v[l--]);while(!v[r++]);
			ans+=(s-l+1)*(r-t+1);
		}
		cout<<ans<<endl;
	}
	return 0;
}

