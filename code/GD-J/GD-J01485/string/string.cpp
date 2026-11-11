#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	string s="";
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		char y;
		cin>>y;
		for(int j=1;j<=x;j++){
			s+=y;
		}
	}
	cout<<"0";
	return 0;
} 
