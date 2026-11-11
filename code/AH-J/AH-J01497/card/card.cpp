#include<bits/stdc++.h>
#define int long long
using namespace std;
int v[567890];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int p=0;
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
		cin>>v[i];
		if(v[i]<v[i-1])p++;
		if(i!=1&&v[i]!=v[i-1]){
		    cout<<i-1<<" ";
		}    
		if(i==n){
		    cout<<n;
		}
	}
    return 0;
}
