#include<bits/stdc++.h>
using namespace std;
int n,x;
string y,s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","r",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>x>>y;
		s+=y;
	}
	if(n==1){
		cout<<0;
		return 0;
	}
	return 0;
}
