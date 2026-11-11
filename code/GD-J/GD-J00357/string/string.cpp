#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+6;
int n,s[maxn],ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int m=1;
	for(int i=1;i<=n;i++){
		int a,c;
		cin>>a>>c;
		int j=a;
		while(j--){
			s[m]=c;
			m++;
		}
	}
	for(int i=1;i<=m;i++){
		if(i>=m-i)break;
		if(s[i]!=s[m-i])ans++;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
