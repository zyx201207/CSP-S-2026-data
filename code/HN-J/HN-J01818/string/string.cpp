#include<bits/stdc++.h>
using namespace std;
int n;
int a[200005];
char c[200005];
int L;
char c1[10000000000];
int k=1;
int ans;
int main(){
//	freopen("string.in","r",stdin);
//	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		L+=a[i];
		for(int j=1;j<=a[i];j++){
			c1[k]=c[i];
			k++;
		}
	}
	if(L%2==1){
	    for(int i=1;i<=L/2+1;i++){
	    	if(c1[i]!=c1[L-i+1]){
    			ans++;
    		}
    	}	
	}
	else{
		for(int i=1;i<=L/2;i++){
	    	if(c1[i]!=c1[L-i+1]){
    			ans++;
    		}
    	}
	}
	cout<<ans;
	return 0;
}
