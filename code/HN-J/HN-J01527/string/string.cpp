#include<iostream>
using namespace std;
int ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	int a;
	char b;
	string S;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>b;
		for(int j=1;j<=a;j++) S+=b;
	}
	for(int i=0;i<S.size()/2;i++){
		if(S[i]!=S[S.size()-i]) ans++;
	}
	cout<<ans;
	return 0;
}
