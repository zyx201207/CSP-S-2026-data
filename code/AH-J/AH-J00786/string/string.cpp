#include <bits/stdc++.h>
using namespace std;
string a[1000010];
int main(){
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	long long int n=0,m=0,x=0;
	cin>>n;
	m=n*2;
	for(int i=0;i<m;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i+=2){
		if(a[i]!=a[m-2-i]){
			x++;
		}
	}
	cout<<x;
	return 0;
}
