freopen(travel,"r",in)
freopen(travel,"w",out)
#include<bits/stdc++.h>
using namespace std;
longlong a[10000],zimu[10000],b[10000];
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		cin>>zimu[i];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
		b[j]=zimu[i];
		}
	}
	int m;
	for(int i=0;i<n;i++){
		m+=a[i];
	}
	for(int i=0;i<m;i++){
		cout<<b[i];
	}
return 0;
}
