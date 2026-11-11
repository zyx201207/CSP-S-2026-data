#include<bits/stdc++.h>
using namespace std;
unsigned long long s;
long long a[20005];
char b[20005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","r",stdout);
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>b[i];
	}
	for(int i=0;i<n/2;i++){
		if(b[i]!=b[n-i-1]) s+=max(a[i],a[n-i-1]);
	}
	cout<<s;

	return 0;
}

