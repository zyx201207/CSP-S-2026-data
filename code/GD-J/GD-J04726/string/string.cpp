#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N=1e6+10;
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,a,k=1,m=0;
    char b,c[N];
    cin>>n;
    for(int i=1;i<=n;i++){
    	cin>>a>>b;
    	for(int j=k;j<=k+a;j++){
    		c[j]=b;
		}
		k+=a;
	}
	for(int i=1;i<k;i++){
		if(c[i]!=c[k-i+1]){
			c[k-i+1]=c[i];
			m++;
		}
	}
	cout<<m;
    return 0;
}
