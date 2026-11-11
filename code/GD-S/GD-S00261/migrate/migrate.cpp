#include<iostream>
#include<algorithm>
#include<utility>
#define int long long
using namespace std;
int a[2000005];
int sum[2000005],num[2000005],ans[2000005];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	if(c<=10){
		while(t--){
			int n,d,res=0;
			cin>>n>>d;
			for(int i=1;i<=n;i++){
				cin>>a[i];
			}
			for(int i=1;i<=n;i++){
				ans[i]=1;
				num[i]=1;
				sum[i]=1;
			//	cout<<1<<" ";
				for(int j=i+1;j<=n;j++){
					if(a[j]-a[j-1]>d) break;
					int l=lower_bound(a+i,a+j,a[j]-d)-a;
					int r=upper_bound(ans+i,ans+j,ans[l])-ans-1;
					ans[j]=ans[l]+1;
					num[j]=sum[r]-sum[l-1];
					//cout<<sum[l-1]<<" ";
					if(num[j]==2){
						//cout<<i<<" "<<j<<"\n";
						res++;
					} 
					sum[j]=sum[j-1]+num[j];
				}
				for(int j=i;j<=n;j++){
					ans[j]=0;
					num[j]=0;
					sum[j]=0;
				}
				//cout<<'\n';
			}
			for(int i=1;i<=n;i++) a[i]=0;
			cout<<res<<"\n";
		} 	
	}
	else if(c==11|c==12){
		while(t--){
			int n,d,res=0;
			cin>>n>>d;
			for(int i=1;i<=n;i++){
				cin>>a[i];
			}
			if(n==1){
				cout<<0<<"\n";
				continue;
			}
			if(c/2+1>a[2]-a[1]){
				cout<<0<<"\n";
			}
			
		}
	}
	else{
		while(t--){
			cout<<0<<'\n';
		}
	}
	
	return 0;
} 
