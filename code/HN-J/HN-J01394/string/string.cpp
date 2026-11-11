#include<bits/stdc++.h>
using namespace std;

int n;
char ch[200010];
int ct;
int ans;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		char c;
		cin>>x>>c;
		for(int j=1;j<=x;j++){
			ch[++ct]=c;
		}
	}
	for(int i=1;i<=(ct>>1);i++){
		if(ch[i]!=ch[ct-i+1]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
} 
