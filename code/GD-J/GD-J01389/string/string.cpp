#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,a[10000],c[10000],num=0;
	string s;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		s=a[i]*c[i]; 
		num++;
	}
	cout<<num-1; 
}
