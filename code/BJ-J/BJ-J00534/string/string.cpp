#include<bits/stdc++.h>
using namespace std;
int n,ans;
long long lens;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		int m;
		char c;
		cin>>m>>c;
		for(int i=0;i<m;i++){
			s+=c;
		}
		lens+=m;
	}
	for(int i=0;i<(lens-1)/2+1;i++){
		if(s[i]!=s[lens-i-1]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
