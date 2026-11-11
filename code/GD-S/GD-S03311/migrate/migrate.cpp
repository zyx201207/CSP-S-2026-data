#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
const long long inf=1e16;
long long a[N],ans,dis[N],f[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	scanf("%d%d",&c,&t);
	int n;
	long long d;
	while(t--){
		scanf("%d%lld",&n,&d);
		bool flag=true;
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
			if(i>2&&a[i]-a[i-1]!=a[2]-a[1])flag=false;
		}
		if(a[n]-a[1]<=d){
			printf("0\n");
			continue;
		}
		ans=0;
		if(flag){
			long long cnt=d/(a[2]-a[1]);
			for(int i=1;i<=n;i++){
				ans+=max(0ll,(n-i+1)/cnt-1);
			}
			printf("%lld\n",ans);
		}else if(n<=5000){
			for(int i=1;i<=n;i++){
				int l=i;
				f[i]=1;
				dis[i]=1;
				for(int j=i+1;j<=n;j++)f[i]=0;
				for(int j=i+1;j<=n;j++){
					while(a[j]-a[l]>d)l++;
//					cout<<"i="<<i<<" ";
//					cout<<"j="<<j<<" ";
//					cout<<"l="<<l<<" ";
					if(l>i)dis[j]=dis[l]+1;
					else dis[j]=1,f[j]=1;
//					cout<<"dis[j]="<<dis[j]<<" ";
					for(int k=l;dis[k]==dis[l]&&k<=j;k++)f[j]+=f[k];
//					cout<<"f[j]="<<f[j]<<" ";
//					cout<<endl;
					if(f[j]==2)ans++;
				}
			}
//			int last=0;
//			bool ff,ff2;
//			for(int i=1;i<=n;i++){
//				last=i;
//				ff=true;
//				ff2=false;
//				for(int j=i+1;j<=n;j++){
//					if(a[j]-a[j-1]>d)break;
//					if(a[j]-a[last]>d){
//						ff2=false;
//						if(last>i&&a[j-1]-a[last-1]<=d)ff2=true;
//						last=j-1;
//					}
//					if(j<n&&last>i&&a[j+1]-a[last]>d&&a[j]-a[last-1]<=d&&((a[j]-a[last-2]<=d&&last-2>=i)||ff2)){
//						break;
//					}
//					cout<<"i="<<i<<" ";
//					cout<<"j="<<j<<" ";
//					cout<<"last="<<last<<" ";
//					cout<<"ff="<<ff<<" ";
//					cout<<"ff2="<<ff2<<" ";
//					cout<<"a[j]-a[last-1]="<<a[j]-a[last-1]<<" ";
//					cout<<"a[j]-a[last-2]="<<a[j]-a[last-2]<<" "; 
//					cout<<endl;
//					if(ff&&!ff2&&last>i&&a[j]-a[last-1]<=d&&(a[j]-a[last-2]>d||last-2<i)){
//						ans++;
//						cout<<"i="<<i<<" ";
//						cout<<"j="<<j<<" ";
//						cout<<"last="<<last<<" ";
//						cout<<"ff="<<ff<<" ";
//						cout<<"ff2="<<ff2<<" ";
//						cout<<endl;
//					}
//					if(!ff&&(last==i||a[j]-a[last-1]>d)){
//						ans++;
//						cout<<"i="<<i<<" ";
//						cout<<"j="<<j<<" ";
//						cout<<"last="<<last<<" ";
//						cout<<"ff="<<ff<<" ";
//						cout<<"ff2="<<ff2<<" ";
//						cout<<endl;
//					}
//					if(j<n&&last>i&&a[j+1]-a[last]>d&&a[j]-a[last-1]<=d){
//						if(ff)ff=false;
//						else{
//							break;
//						}
//					}
//				}
//			}
			printf("%lld\n",ans);
		}else{
			printf("0\n");
		}
	}
	return 0;
} 
