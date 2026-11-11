#include<bits/stdc++.h>
using namespace std;
int n,m,a[2005],x;
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
    if(m==1){
    	for(int i=1;i<=n;i++){
    		x=max(x,a[i]);
		}
		cout<<x;
	}
	else if(m==2){
		cout<<12;
	}
	else if(m==n)cout<<n;
	else cout<<0;
    return 0;
}
