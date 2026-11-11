#include<bits/stdc++.h>
using namespace std;
string S;
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n,ste=0;
	cin>>n;
	for(int i=1;i<=n;i++){
        int a;
		string c;
		cin>>a>>c;
		for(int j=0;j<a;j++){
			S=S+c;
		}
	}
	int lo=S.size();
	for(int i=0;i<=lo/2-1;i++){
		if(S[i]!=S[lo-i-1])ste++;
	}
	cout<<ste;
	return 0;
}
