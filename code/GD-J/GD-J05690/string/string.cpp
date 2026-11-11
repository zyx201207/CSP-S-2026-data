#include<bits/stdc++.h>
using namespace std;
long long n,s,l,a[200005];
string c[200005],b[1000005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<a[i];j++){
			b[s]=c[i];
			s++;
		}
	}
	for(int i=0;i<s/2;i++){
		if(b[i]!=b[s-i-1]){
			l++;
		}
	}
	cout<<l;
	return 0;
}
