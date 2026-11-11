#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,ans=0,x=0,k=1;
	cin>>n;
	int a[n];
	char m[n];
	if(n%2==0)
	    ans=n/2;
	else
	    ans=n/2+1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cin>>m[i];
    }
	for(int j=1;j<=n;j++){
		if(j>ans&&m[j]!=m[j-k]){
			x=x+a[j-k];
			k=k+2;
		}
	}
	cout<<x;
	return 0;
}
