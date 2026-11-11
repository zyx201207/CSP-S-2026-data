#include<bits/stdc++.h>
using namespace std;
queue<char> vis;
char s[200010];
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for (int i=1;i<=n;i++) {
		int a;
		char b;
		cin>>a>>b;
		for (int j=1;j<=a;j++) {
			vis.push(b);
		}
	}
	int l=vis.size();
	for (int i=1;i<=l;i++) {
		int x=vis.front();
		vis.pop();
		s[i]=x;
	}
	int sum=0;
	for (int i=1;i<=l/2;i++) {
		if (s[i]!=s[l-i+1]){
			sum++;
		}
	}
	cout<<sum;
	return 0;
}
