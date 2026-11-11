#include<bits/stdc++.h>
using namespace std;
int a[200005];
string s,v; 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int c=0,t=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s[i];
		for(int j=1;j<=a[i];j++){
			v+=s[i];
		}
	}
	c=v.size();
		for(int i=c/2;i>=0;i--){
			if(v[i]!=v[c-i-1]){
				t++;
			}
		}
	cout<<t;
	return 0;
}
