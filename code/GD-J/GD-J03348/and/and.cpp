#include<iostream>
#include<algorithm>
using namespace std;
int n,m,a[200003],sum[33][200003],last[33];
int ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=2000&&(m==1||m==2||m==n)){
		if(m==1){
			for(int i=1;i<=n;i++){
				ans=max(ans,a[i]);
			}
			cout<<ans;
			return 0;
		}
		else if(m==2){
			for(int i=1;i<n;i++){
				for(int j=i+1;j<=n;j++){
					ans=max(ans,a[i]&a[j]);
				}
			}
			cout<<ans;
			return 0;
		}
		else if(m==n){
			for(int i=1;i<=n;i++)ans=ans&a[i];
			cout<<ans;
			return 0;
		}
	}
	else{
		sort(a+1,a+n+1);
		reverse(a+1,a+n+1);
		for(int i=30;i>=0;i--){
			for(int j=1;j<=n;j++){
				sum[i][j]=sum[i][j-1]+( (a[j]&(1<<i)) != 0 );
					if( sum[i][j]<=m && (a[j]&(1<<i))!=0 )last[i]=j;
//				cout<<sum[i][j]<<" ";
			}
//			cout<<"\n";
		}
		int edge=n;
		for(int i=30;i>=0;i--){
			if(sum[i][edge]>=m){
				edge=min(edge,last[i]);
				ans+=(1<<i);
			}
//			cout<<i<<":"<<edge<<"\n";
		}
		cout<<ans;
	}
	return 0;
}
