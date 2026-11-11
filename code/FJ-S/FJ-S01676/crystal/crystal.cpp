#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long c[500010]={0};
	long long de[500010]={0}; //a[i]-a[i-1]的差 
	long long n,m; //n颗能量水晶 至多m次操作
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>c[i];
	}
	sort(c,c+n);
	for(int i=1;i<n;i++){
		de[i]=c[i]-c[i-1];
	}
	long long big[n+10][n+10];
	long long cnt=0;
	for(int head=0;head<n;head++){
		for(int tail=head;tail<n;tail++){
			cnt=0;
			for(int i=tail;i>head;i--){
				cnt+=c[tail]-c[i];
			}
			big[head][tail]=cnt;
		}
	}
	int ans=-1;
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			if(big[i][j]<=m){
				ans=max(ans,j-i+1);
			}
		}
	}
	cout<<ans;		
	return 0;
} 
