#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
char s[10005];
int n;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int tmp=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		int a;
		char b;
		cin>>a>>b;
		for(int j=1;j<=a;j++){
			s[tmp]=b;
			tmp++;
		}
	}
	if(n==1){
		cout<<0;
	}
	
	
	return 0;
} 
