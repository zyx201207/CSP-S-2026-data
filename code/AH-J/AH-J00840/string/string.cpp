#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
	cin.tie(NULL);
	ios::sync_with_stdio(0);
	long long n,m,cnt=0;
	string x,y,z;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>m>>y;
		for(int j=0;j<m;j++){
			x=x+y;
			z=y+z;
		}
	}
	if(x==z){
		cout<<"0";
		return 0;
	}
	for(int i=0;i<x.size()/2;i++){
		if(x[i]!=z[i]){
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
