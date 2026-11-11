#include<bits/stdc++.h> 
using namespace std;
#define lint long long
int a[5002];
int dp[5002][5002];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	int n,m;
	
	cin>>n>>m;
	int ans=1;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
//	cout<<"333"<<endl;
	for(int i=1;i<n;i++){
		for(int j=0;j<i;j++){
			if(dp[j][i-1]==-91){
				dp[j][i]=-91;
//				cout<<"222"<<endl;
				continue;
			}
//			cout<<"111"<<endl;
			int num=(i-1)-j+1;
			int de=a[i];
			int ma=a[i-1];
			int st=num*(de-ma)+dp[j][i-1];
			if(st<=m){
				dp[j][i]=st;
//				cout<<"000"<<endl;
				ans=max(ans,num+1);
			}
			else{
				dp[j][i]=-91;
			}
		}
	}
		
//	}
//	for(int i=0;i<n;i++){
//		cout<<a[i]<<" ";
//	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
