#include <bits/stdc++.h>
using namespace std;
int l,n;
int sum;
string a;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		int j;
		string s;
		cin>>j>>s;
		while(j--){
			a+=s;
		}
	}
	l=a.size();
	for(int i=0;i<=l/2;i++){
		if(a[i]!=a[l-i-1]){
			sum++;
		}
	}
	cout<<sum;
	return 0;
}
