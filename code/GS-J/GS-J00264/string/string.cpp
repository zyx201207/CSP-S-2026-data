#include<bits/stdc++.h>
using namespace std;
int n;
string w;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i = 1;i<=n;i++){
		int sum;char a;
		cin>>sum>>a;
		while(sum--){
			w+=a;
		}
	}
	long long len = w.size(),ans = 0;
	for(int i = 0,j = len-1;i<len/2;i++){
		if(w[i] != w[j]){
			ans++;
		}
		j--;
	}
	cout<<ans;
} 

