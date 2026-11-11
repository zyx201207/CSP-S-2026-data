#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	char a[n],b[n];
	for(int i=0;i<n;i++){
		cin>>a[i]>>b[i];
	}
	cout<<n-1;
	return 0;
}
