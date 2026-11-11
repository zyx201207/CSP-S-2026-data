#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll m,n,a[1000010],cnt;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio();
	cin.tie(0);
	cout.tie(0);
	cin>>m>>n;
	 for(ll i=1;i<=n;i++){
	 	cin>>a[i]; 
	 }
	 for(ll i=1;i<=n;i++){
	    for(int j=1;j<=m-1;j++){
	 	    for(ll k=2;k<=n;k++){
	 		    if((a[i] and a[k])>cnt){
	 			    cnt+=a[i] and a[k];
			    }
		    }
		 }
	 }
	 cout<<cnt<<"\n"; 
}
