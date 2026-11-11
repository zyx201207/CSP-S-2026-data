#include<bits/stdc++.h>
using namespace std;
#define int long long

int n,p,mid,maxn=0;
string s,q;

signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>p>>q;
		for(int j=0;j<p;j++){
			s=s+q;
		}
	}
	mid=s.size()/2;
	for(int i=0;i<mid;i++){
		if(s[i]!=s[s.size()-1-i]){
			maxn++;
		}
	}
	cout<<maxn<<endl;
	return 0;
}
