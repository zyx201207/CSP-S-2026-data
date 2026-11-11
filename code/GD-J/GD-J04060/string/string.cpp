#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string a=" ";
	for(int i=1;i<=n;i++){
		int x;
		char c;
		cin>>x>>c;
		for(int j=1;j<=x;j++){
			a+=c;
		}
	}
	int cnt=0,l=a.size();
	for(int i=1;i<=l/2;i++){
		if(a[i]!=a[l-i]) cnt++;
	}
	cout<<cnt;
	return 0;
}
