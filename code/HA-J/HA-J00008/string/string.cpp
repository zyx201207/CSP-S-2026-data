#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string S;
	int n;
	long long z,cnt=0;
	cin>>n;
	string p="";
	for(int i=0;i<n;i++){
		cin>>z>>p;
		for(int j=0;j<z;j++){
			S=S+p;
		}
	}
	for(int i=0;i<n;i++){
		if(S[i]!=S[n-1-i]){
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}