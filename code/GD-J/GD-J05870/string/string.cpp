#include<bits/stdc++.h>
using namespace std;
char a[200005];
int n,i,j,k[200005]; 
long long s;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++) cin>>k[i]>>a[i];
	for(i=1,j=n;i<j;){
	    int mini=min(k[i],k[j]);
		if(a[i]!=a[j]) s+=mini;
		
		k[i]-=mini,k[j]-=mini;
		if(k[i]==0) i++;
		if(k[j]==0) j--;
	}
	cout<<s;
	return 0;
}
