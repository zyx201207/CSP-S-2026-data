#include<bits/stdc++.h>
using namespace std;
int N=100;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,a[N],c[N],ans;
	cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
    	for(int j=1;j<=n;j++){
    		if(a[i]-a[j]==m){
    			ans++;
			}
		}
	}
	cout<<ans+1; 
    return 0;
}    
 
