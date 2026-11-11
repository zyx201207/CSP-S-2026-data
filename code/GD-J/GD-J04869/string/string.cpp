#include <bits/stdc++.h>
using namespace std;
long long int n,a[200005],c[200005];
char b[200005];
int main(){
    freopen("string.in","r",stdin);
	freopen("string.out","W",stdout);
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i]>>b[i];
    if(n<=1){
    	cout<<"0";
    	return 0;
	}
	for(int i=0;i<n;i++){
		c[b[i]-'a']++;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(c[j]<c[j+1]) swap(c[j],c[j+1]);
			if(a[j]<a[j+1]) swap(a[j],a[j+1]);
		}
	}
	if(c[0]==n) cout<<"0";
	else cout<<c[0]*a[0];
	return 0;
} 
