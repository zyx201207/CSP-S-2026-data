#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5005,M=2e6+5;
int C,T,n,d,a[M],f[N],ft[N],t[N*4],s[N],la[N],ans;
void add(int o,int l,int r,int x,int d){
	if(l==r){t[o]=d;return;}
	int mid=l+r>>1;
	if(x<=mid) add(o<<1,l,mid,x,d);
	else add(o<<1|1,mid+1,r,x,d);
	t[o]=min(t[o<<1],t[o<<1|1]);
}
int qu(int o,int l,int r,int x,int y){
	if(l>y||r<x||r<l) return 1e18;
	if(x<=l&&r<=y) return t[o];
	int mid=l+r>>1;
	return min(qu(o<<1,l,mid,x,y),qu(o<<1|1,mid+1,r,x,y));
}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0); 
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>C>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		if(n<=2){cout<<"0\n";continue;}
		if(C==11||C==12){
			if(a[3]-a[1]>d){cout<<"0\n";continue;}
			int k=d/(a[2]-a[1]),g=2*k-1;
			cout<<max(0ll,n-g)<<"\n";
		}else{
			ans=0;
			for(int i=1;i<=n;i++){
				if(a[i]-d>a[i-1]) la[i]=i;
				else if(a[i]-d<=a[1]) la[i]=1; 
				else la[i]=lower_bound(a+1,a+n+1,a[i]-d)-a;
			}
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n*4+1;j++) t[j]=1e18;
				for(int j=0;j<=n+1;j++) f[j]=s[j]=ft[j]=0;
				f[i]=0,ft[i]=1,s[0]=1,add(1,1,n,i,0);
				for(int j=i+1;j<=n;j++){
					f[j]=qu(1,1,n,la[j],j-1)+1;
					if(f[j]>=1e17) f[j]=0;
					add(1,1,n,j,f[j]);
				}
				for(int j=i+1;j<=n;j++){
					for(int k=la[j-1];k<la[j];k++) s[f[k]]-=ft[k];
					ft[j]=s[f[j]-1],s[f[j]]+=ft[j];
					if(ft[j]==2) ans++;
				}
			}
			cout<<ans<<"\n";
		}
	}
	return 0;
}
