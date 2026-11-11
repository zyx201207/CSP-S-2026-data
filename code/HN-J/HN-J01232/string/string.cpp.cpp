#include <bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
int n;
int a;
char s;
int ans;
int k[maxn];
int cnt;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>s;
		for(int j=1;j<=a;j++){
			k[++cnt]=s-'0';
		}
	}
	for(int i=1;i<=cnt/2;i++){
		if(k[i]!=k[cnt+1-i]){
			ans++;
		}
	}
	printf("%d",ans);
	return 0;
}
