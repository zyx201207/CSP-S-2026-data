#include<bits/stdc++.h>
using namespace std;
int n,ans;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int a;
		char c;
		scanf("%d%c",&a,&c);
		for(int i=0;i<a;i++) s+=c;
	}
	int l=s.length();
	for(int i=0;i<(l>>1)+1;i++){
		if(s[i]!=s[l-i]){
			s[l-i]=s[i];
			ans++;
		}
	}
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
