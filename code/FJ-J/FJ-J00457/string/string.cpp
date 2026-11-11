#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string a;
	char k;
	int n,m,s=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>m;
		cin>>k;
		for(int j=0;j<m;j++){
			a[s]=k;
			s++;
		}
	}
	n=0;
	int j=s-1;
	for(int i=0;i<s/2;i++){
		if(a[i]!=a[j]) n++;
	}
	cout<<n;
	return 0;
}
