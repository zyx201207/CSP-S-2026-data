#include<bits/stdc++.h>
#define wef(i,l,r) for(int i=l;i<=r;i++)
#define few(i,r,l) for(int i=r;i>=l;i--)
#define pii pair<int,int>
#define int long long
#define endl cout<<"\n"
using namespace std;
using ll=long long;
const int N=2e6+5;
int a[N],R[N];
int sum[10][10],f[10][10];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int c,T;
	cin>>c>>T;
	if(c==11||c==12){
		while(T--){
			a[2]=0;
			int n,d;
			cin>>n>>d;
			wef(i,1,n) cin>>a[i];
			if(n==1){
				cout<<0<<"\n";
				continue;
			}
			int D=a[2]-a[1],p=d/D;
			if(p<=1||a[1]+2*d>a[n]) cout<<0<<"\n";
			else cout<<n-2*p+1<<"\n";
		}
		return 0;
	}
	if(c==1||c==2){
		while(T--){
			memset(sum,0,sizeof sum);
			int n,d;
			cin>>n>>d;
			wef(i,1,n) cin>>a[i];
			for(int l=1,r=1;l<=n;l++){
				if(l>r) r=l;
				while(r<=n&&a[r]-a[l]<=d) r++;
				R[l]=r-1;
			}
//			memset(f,0x3f,sizeof f);
			wef(i,1,n){
				wef(j,i+1,n){
					int p=i,s=0;
					while(p!=R[p]&&R[p]<j) s++,p=R[p];
					if(p!=R[p]) f[i][j]=s+1;
				}
			}
			wef(s,0,(1<<n)-1){
				if(__builtin_popcount(s)<2) continue;
				int st=0,lst=0,ed=0;
				bool F=1,fst=0;
				wef(i,0,n-1){
					if((s>>i)&1){
						ed=i;
						if(!fst) fst=1,st=lst=i;
						else{
							if(a[i+1]-a[lst+1]>d){
//								cout<<i+1<<" "<<lst+1<<" "<<a[i+1]<<" "<<a[lst+1]<<"\n";
								F=0;
								break;
							}
							lst=i;
						}
					}
				}
				if(F&&__builtin_popcount(s)==f[st+1][ed+1]+1){
					sum[st+1][ed+1]++;
				}
			}
			int res=0;
			wef(i,1,n){
				wef(j,1,n){
//					cout<<sum[i][j]<<" ";
					if(sum[i][j]==2) res++;
				}
//				endl;
			}
			cout<<res<<"\n";
		}
	}
	return 0;
}
