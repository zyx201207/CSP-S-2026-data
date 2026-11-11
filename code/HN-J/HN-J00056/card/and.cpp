#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("and.in","r" ,stdin);
	freopen("and.out","w" ,stdout);
	long long n,m;
	int x[10000];
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>m;
		x[i]=m;
	}
	for(int i=0;i<n;i++){
		cout<<x[i]<<" ";
	}
	
	return 0;
}
