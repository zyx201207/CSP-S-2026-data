#include <bits/stdc++.h>
using namespace std;
unsigned long long n,a[100000000],cnt=0;
char b[100000000];
vector <char> c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			c.push_back(b[i]);
		}
	}
	for(int i=0;i<c.size()/2;i++){
		if(c[i]!=c[c.size()-i]){
		cnt++;	
		}
		}	
		cout<<cnt;
	return 0;
}
