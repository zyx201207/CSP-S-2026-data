#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,x=0,y=0,ans=0;
	cin>>n;
	long long a[n];
	string b;
	char c[n];
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
		x+=a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<a[i];j++){
			b[y]=c[i];
			y++;
		}
	}
	for(int i=0;i<x/2;i++){
		if(b[i]!=b[x-i-1]){
			ans++;
		}
    }
    cout<<ans;
	return 0;
}
