#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	char a[200005];
	long long b[200005];
	string s;
	int n;
	long long ans;
	cin>>n;
	if(n==1){
		cout<<0;
		return 0;
	}
	for(int i=0;i<n;i++){//´Ó0±àºÅ 
	    cin>>b[i]>>a[i];
    }
    if(n==2){
    	if(a[0]!=a[1] )cout<<min(b[0],b[1]);
    	else cout<<0;
    	return 0;
	}
    int x=n/2;
    if(n%2==0){
    	for(int i=0;i<=x;i++){
    		if(x<n){
    			if(a[i]!=a[n-1]){
    				if(b[i]==b[n-1]) ans+=b[i];
    				else ans+=min(b[i],b[n-1]);
				}
				else{
					if(b[i]>b[i-1]) ans+=b[i]-b[i-1];
					else ans+=b[i-1]-b[i];
				}
    			n--;
			}
		}
		cout<<ans;
		return 0;
	}
	cout<<1; 
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
