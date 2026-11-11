#include<bits/stdc++.h>
using namespace std;
long long a[200005];
char b[200005];
long long c=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>b[i];
	}
	for(int i=0;i<n;i++){
		if(b[i]!=b[n-1-i]){
			c+=a[n-1-i];
		}
	}
	cout<<c;
	return 0;
}
