#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,s=0;
	string a;
	cin>>n;
	for(int i=1;i<=n;i++){
		int m;
		string k;
		cin>>m>>k;
		for(int j=1;j<=m;j++)a+=k;
	}
	int l=1,r=a.size();
	while(l<r){
		if(a[l-1]!=a[r-1])s++;
		l++;
		r--;
	}
	cout<<s;
}
