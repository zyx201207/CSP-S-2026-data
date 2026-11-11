#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long num=0,q;
	string wuguan;
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>q>>wuguan;
		num+=q;
	}
	cout<<num/2;
	return 0;
}
