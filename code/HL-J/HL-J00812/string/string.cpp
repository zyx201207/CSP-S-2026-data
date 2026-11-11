#include <bits/stdc++.h>
using namespace std;
int main(){
//	freopen("string.in","r",stdin);
//	freopen("string.out","w",stdout);
	int n;
	long long cnt=0,ans=0;
	char s[2011000];
	cin>>n;
	for(int i=1;i<=n;i++){
		int shu;
		char y;
		cin>>shu>>y;
		for(int j=1;j<=shu;j++){
			s[cnt+j-1]=y;
		}
		cnt+=shu;
	}
	for(int i=0,j=cnt-1;i<=cnt/2-1,j>=cnt/2;i++,j--){
		if(s[i]!=s[j]){
			ans++;
		}
	}
	cout<<ans;
}