#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,a[200001],b=0;
	char c[200001];
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>c[i];
	if(n==1)
		return cout<<0,0;
	for(int i=1;i<n;i++){
		if(c[i]==c[i+1])
			continue;
		b=1;
		break;
	}
	if(!b)
		return cout<<0,0;
	for(int i=1;i<n;i++){
		if(c[i]==c[i+1]){
			a[i+1]+=a[i];
			a[i]=0;
		}
	}
	return 0;
}
