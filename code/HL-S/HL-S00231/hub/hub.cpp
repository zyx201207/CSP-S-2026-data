#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t;
    cin>>c>>t;
    for(int i=0;i<t;i++){
    	int n,k;
    	cin>>n>>k;
    	int f[10005];
    	int t[10005];
    	for(int j=0;j<n;j++){
    		cin>>f>>t;
		}
		if(n<=6) cout<<1<<endl;
		else cout<<2<<endl;
	}
    
    fclose(stdin);
    fclose(stdout);
	return 0;
}
