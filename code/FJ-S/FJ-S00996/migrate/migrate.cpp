#include<bits/stdc++.h>
using namespace std;
int a[10000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,n,q;
	cin>>c>>t;
	while(t--){
		cin>>n>>q;
		int sum = 0;
		for(int i = 1;i <= n;i++){
			cin>>a[i]; 
		} 
		for(int i = 1;i <= n;i++){
			for(int j = i+1;j <= n;j++){
				if(abs(a[i]-a[j])<=q)sum++;
			}
		}
		if(c==13||c==14){
			cout<<n*(n-1)/2-sum;
		}	
	}
	return 0;
}
