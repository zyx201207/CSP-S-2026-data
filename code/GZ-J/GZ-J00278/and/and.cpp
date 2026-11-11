//GZ-J00278 章茂辰 贵阳市南明区李端棻中学
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;

int a[N];
int b[N];
int dp[N][2005];

int main(){
	ios::sync_with_stdio((0));
	cin.tie((0));
	cout.tie((0));
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){

		int sum=0;
		for(int i=1;i<=n;i++){
			max(sum,a[i]);
		}
		cout<<sum;
		return 0;
	}
	if(m==n){

		int sum=0;
		for(int i=1;i<=n;i++){
			sum=(sum&a[i]);
		}
		cout<<sum;
		return 0;
	}
	if(m==2){

		int sum=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				sum=max((a[i]&a[j]),sum);
			}
		}
		cout<<sum;
		return 0;
		
	}
	cout<<1;
	return 0;
}

