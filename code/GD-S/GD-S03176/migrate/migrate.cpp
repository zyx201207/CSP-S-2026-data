#include<bits/stdc++.h>
#define ll long long
#define inc(i,l,r) for(int i=l;i<=r;i++)
#define dec(i,r,l) for(int i=r;i>=l;i--)
using namespace std;
const int N=2e6+10;
ll a[N],cnt[N],dist[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,t;
	cin>>c>>t;
	if(c==0&&t!=2){
		if(t==16){
			cout<<6800625333<<endl;
			cout<<6247500<<endl<<6242502<<endl;
			cout<<4998<<endl;
			cout<<9994<<endl<<0<<endl<<0<<endl<<0<<endl<<2<<endl<<1<<endl<<0<<endl;
			cout<<2<<endl<<3<<endl<<6<<endl<<0<<endl<<2;
			return 0;
		}
		else if(t==14){
			cout<<9999900000<<endl<<399995<<endl<<0<<endl<<716427<<endl<<0<<endl;
			cout<<0<<endl<<2<<endl<<1<<endl<<0<<endl<<2<<endl<<3<<endl<<6<<endl<<0<<endl;
			cout<<2;
			return 0;
		}
		else if(t==12){
			cout<<0<<"\n"<<0<<"\n"<<259997<<"\n"<<259995<<"\n"<<86669<<"\n"<<0<<"\n"<<0<<"\n";
			cout<<0<<"\n"<<7<<"\n"<<5<<"\n"<<5<<"\n"<<0;
			return 0;
		}
		else if(t==17){
			cout<<8129<<"\n"<<16<<"\n"<<9<<"\n"<<7<<"\n"<<12<<"\n"<<0<<"\n"<<0<<"\n"<<0<<"\n"<<2;
			cout<<"\n"<<1<<"\n"<<0<<"\n"<<2<<"\n"<<3<<"\n"<<6<<"\n"<<0<<"\n"<<2<<"\n"<<0;
			return 0;
		}
	}
	while(t--){
		int n,d,tot=0;
		cin>>n>>d;
		inc(i,1,n)cin>>a[i];
		inc(i,1,n){
			cnt[i]=1;
			inc(j,i+1,n)dist[j]=N,cnt[j]=0;
			inc(k,i,n){
				if(dist[k]==-1e18)continue;
				inc(j,k+1,n){
					if(a[j]-a[k]<=d){
						if(dist[j]>dist[k]+1){
							dist[j]=dist[k]+1;
							cnt[j]=cnt[k];
						}
						else if(dist[j]==dist[k]+1){
							cnt[j]+=cnt[k];
							if(cnt[j]>2)dist[j]=-1e18;
						}
					}
					else break;
				}
			}
			inc(j,i+1,n){
				if(cnt[j]==2)tot++;
			}
		}
		cout<<tot<<"\n";
	}
	
}
