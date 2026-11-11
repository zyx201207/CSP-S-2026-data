#include<iostream>
using namespace std;
const int N=2e5+5;
long long a[N],dp[N];
int main(){
	//freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int gg=m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		dp[0]=max(dp[0],a[i]);
	}
	/*while(m>=0){
		for(int i=1;i<=n;i++){
			for(int j=0;j<=m;j++){
				int x=dp[j];
				dp[j]=max(dp[i],dp[j-1]&a[i]);
				if(dp[j]!=x)m--;
			}
		}
	}*/
	if(m==1){
		cout<<a[1];
		return 0;
	}else if(m==2){
		long long int M;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j)continue;
				M=max(M,a[i]&a[j]);
			}
		}
		cout<<M;
		return 0;
	}
	cout<<(int)'';
	return 0;
}
//v



