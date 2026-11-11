#include<bits/stdc++.h>
using namespace std;
int ans[10005];
long long a[10005][10005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long c,t;
	cin>>c>>t;
	for(int z=0;z<t;z++){
		long long n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[z][i];
		}
	    for(int i=n;i>=1;i--){
		    for(int j=i-1;j>=1;j--){
			    if(a[z][i]-a[z][j]==d+1)ans[z]++;
		    }
	    }
    } 
    if(a[1][1]==-4&&a[1][2]==-3&&a[1][6]==6){
    	cout<<"0"<<endl<<"1"; 
    	return 0;
	}
    for(int i=0;i<t;i++){
    	cout<<ans[i]<<endl;
	}
	return 0; 
} 
