#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+3;int bj;
int x,T,n,d,a[N],b[N],lst,ans;
signed main(){
	freopen("migrate.in","r",stdin);freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>x>>T;while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;++i)cin>>a[i];
		for(int i=1;i<=n;++i){
			int l=i,r=n+1,mid;
			while(l<r){
				mid=l+r>>1;
				if(abs(a[mid]-a[i])>d) r=mid;
				else l=mid+1;
			}b[i]=l-1;
		}for(int i=1;i<=n;++i){
			lst=i,x=b[i],bj=0;
			while(x!=lst){
				if(x>lst+1){
					if(!bj){
						if(x-2==lst) ans+=b[x-1]-x;
						else ans+=b[x-1]-max(x,b[x-2]);
					}else{if(bj==2)ans+=b[x]-b[x-1];}
					if(bj==2){
						if(b[x]!=b[x-1])bj=2;
						else break;
					}else{
						if(b[x]-b[x-1]>1) bj=0;
						else if(b[x]-b[x-1]==1) bj=1;
						else if(bj==0&&(x-2==lst||b[x-2]!=b[x])) bj=2;
						else break;
					}
				}else{
					if(bj==2) ans+=b[x]-x;
					if(bj==1) bj=0;
				}lst=x,x=b[x];
			}
		}cout<<ans<<'\n',ans=0;
	}return 0;
}
