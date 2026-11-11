#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int a[200005];
	string c[200005];
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
	}
	string S = "";
	int L = 0;
	int ans = 0,hui = 1;
	for(int i=0;i<n;i++){
		for(int j=0;j<a[i];j++){
			S = S + c[i];
		}
		L = L+a[i];
	}

	for(int i=L/2;i>=0;i--){
		if(S[i] != S[L-1-i]){
			ans++;
		}
	}

	cout<<ans;
	
	return 0;
}
