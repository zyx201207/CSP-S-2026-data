#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
	int n,s[1005];
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	for(int j=1;j<=n;j++){
		for(int i=n;i>=1;i--){
			if(s[j]==s[i]){
				cout<<0;
				break;
			}
		}
	}
	return 0;
}

