#include<bits/stdc++.h>
using namespace std;
string s;
int n,c,ans;
char z;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	getchar();
	for(int i=1;i<=n;i++){
		scanf("%d %c",&c,&z);
		getchar();
		for(int j=1;j<=c;j++) s+=z;
	}
	for(int i=1;i<=s.size()/2;i++){
		if(s[i-1]!=s[s.size()-i]) ans++;
	}
	printf("%d\n",ans);
	return 0;
}
