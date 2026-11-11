#include<bits/stdc++.h>
using namespace std;
int n,a,ans;
string s;
char c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	while(n--){
		scanf("%d %c",&a,&c);
		while(a--)s+=c;
	}
	for(int i=0;i<s.size()/2;i++)
		if(s[i]!=s[s.size()-1-i])ans++;
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

