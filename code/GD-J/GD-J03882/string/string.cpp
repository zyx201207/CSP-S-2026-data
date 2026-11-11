#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n; 
	string c;
	for(int i=0;i<n;i++){
		int a;
		char b;
		cin>>a>>b;
	for(int i=1;i<=a;i++){
		c+=b;
		} }
	int cnt=0;
	for(int i=0;i<c.size()/2;i++){
		if(c[i]!=c[c.size()-i-1]){
			cnt++;
			}
			
		}
	cout<<cnt;
	return 0;}
 
