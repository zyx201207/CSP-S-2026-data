#include<bits/stdc++.h>
using namespace std;
int cuns[10001];
char shur[10001];
char s[10081];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>cuns[i]>>shur[i];
		if(shur[i]==shur[i+1]==shur[i+2]){
			cout<<"0";
			return 0;
		}
	}
	for(int j=1;j<=n;j++){
		int shude=cuns[j];
		for(int i=1;i<=shude;i++){
			shur[i]=s[shude];
		}
	}
	cout<<s<<endl;
	return 0;
}
