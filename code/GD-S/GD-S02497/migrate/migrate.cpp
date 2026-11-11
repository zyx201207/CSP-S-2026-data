#include<bits/stdc++.h>
using namespace std;
#define For(i,s,e) for(int i=s;i<=e;i++)
#define dFor(i,s,e) for(int i=s;i>=e;i--)
#define int long long
const int M=2e6+10;
int c,t,n,d,ans,a[M],dis[M],wy[M];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--){
		scanf("%lld%lld",&n,&d);
		int f=0;
		For(i,1,n)scanf("%lld",a+i);
		For(i,1,n)if(a[i]-a[1]<=d && a[n]-a[i]<=d){f=1;break;}
		ans=0;
		if(c==11 || c==12 || f){
			int en=a[2]-a[1];
			int l=d/en,ll=(a[n]-a[1])/en;
//			cout<<ll<<" "<<l<<endl;
			if(l>1){
				ans=ll-(l*2-1)+1;
			}
			ans=max(0ll,ans);
		}else if(c==13 || c==14){
			int tr=1;
			For(l,1,n){
				while(a[tr+1]-a[l]<=d && tr+1<=n)tr++;
				dFor(r,n,1){
					if(a[r]-a[tr-1]<=d){
						if(a[r]-a[tr-2]<=d)break;
						else ans++;
					}
				}
				if(a[n]-a[tr-2]<=d)break;
			}
		}else{
			For(i,1,n){
				int k=i,l;
				wy[i]=1;dis[i]=0;
				For(j,i+1,n){
					while(k<=j && a[j]-a[k]>d)k++;
					dis[j]=dis[k]+1;
					l=k;wy[j]=0;
					while(l<j && dis[l]==dis[k])wy[j]+=wy[l++];
					if(wy[j]==2)ans++;
//					cout<<j<<" "<<dis[j]<<" ";
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
/*
1 1
*/
