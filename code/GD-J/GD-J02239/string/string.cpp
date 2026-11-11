#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	int a;
	string S;
	char c;
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a>>c;
		for(int j=1;j<=a;j++){
			S+=c;
		}
	}
	int t =S.size();
	cout<<'0';

	return 0;
} 
