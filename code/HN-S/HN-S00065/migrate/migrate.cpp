#include<bits/stdc++.h>
using namespace std;
int a[100000];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c;
	int t;
	cin>>c>>t;
	while(t--){
		int ans=0;
		int n;
		int d;
		cin>>n>>d;
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		for(int i=c;i<n;i++){
			if(a[i+3]-a[i]==d+1){
				ans++;
			}
		} 
		cout<<ans;
	}
	return 0;
	fclose(stdin);
    fclose(stdout);
} 
