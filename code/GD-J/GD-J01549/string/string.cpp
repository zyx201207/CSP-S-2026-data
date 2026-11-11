#include<bits/stdc++.h>
using namespace std;
vector<char> v;
int n,l=0,r,ans; 
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int m;char ch;
		cin>>m>>ch;
		r+=m;
		for(int i=1;i<=m;i++){
			v.push_back(ch);
		}
	}
	r--;
	while(l<=r){
		if(v[l]!=v[r]) ans++;
		l++;r--;
	}
	cout<<ans<<endl;
	return 0;
} 
