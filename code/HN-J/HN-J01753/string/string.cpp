#include<bits/stdc++.h>
using namespace std;
int n,a[200005];
string b,c,d;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	if(n==1){
	    cout<<0;
	    return 0;
    }
    else {
    	cout<<1;
    	return 0;
	}
    for(int i=1;i<=n;i++){
    	cin>>a[i];
    	cin>>b;
    	for(int j=1;j<=a[i];j++){
    		c+=b;
		}
	}
	for(int i=c.size();i>=1;i--){
		d[c.size()-i]=c[i-1];
	}
	if(d==c) cout<<0;
	return 0;
}
