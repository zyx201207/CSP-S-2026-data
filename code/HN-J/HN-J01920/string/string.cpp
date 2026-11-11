#include<bits/stdc++.h>
using namespace std;
#define int long long
string s;
int w,m;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int g;
		char r;
		cin>>g>>r;
		while(g--){
			s=s+r;
		}
	} 
	w=s.size();
	for(int i=0;i<w/2;i++){
		if(s[w-i-1]!=s[i]){
			m++;
		}
	}
	cout<<m;
	return 0;
}

