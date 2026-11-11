#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    for(int i=1;i<=t;i++){
    	int n,d;
    	int a[10005]={0};
    	cin>>n>>d;
    	for(int j=0;j<n;j++){
    		cin>>a[j];
		}
		if(n<2d) cout<<0;
		else if(n/2==0) cout<<1;
		else cout<<0;
	}
    fclose(stdin);
    fclose(stdout);
	return 0;
}
