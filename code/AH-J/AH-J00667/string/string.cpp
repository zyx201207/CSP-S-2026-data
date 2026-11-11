#include<bits/stdc++.h>
using namespace std;
int n,l,cnt;
char c,s[1000010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int t=0;
	for(int i=1;i<=n;i++){
		cin>>l>>c;
		for(int j=1;j<=l;j++){
			s[++t]=c;
		}
	}
	for(int i=1;i<=t/2;i++){
		if(s[i]!=s[t+1-i]){
			cnt++;
		}
	}
	cout<<cnt;
	
	return 0;
}
