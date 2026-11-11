#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
    int c,t;
    int a[1000000];
    cin>>c>>t;
    while(t--){
    	int n,d;
    	cin>>n>>d;
    	for(int i=1;i<=n;i++){
    		cin>>a[i];
		}
		cout<<n-d*2+1;
	}
	return 0;
}
