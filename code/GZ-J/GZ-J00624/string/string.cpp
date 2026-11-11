//GZ-J00624 毕节梁才学校  赵纤茹
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int n;
LL m;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	s=' ';
	for(int i=1;i<=n;i++){
		LL num;
		char x;
		cin>>num>>x;
		m+=num;
		for(int j=1;j<=num;j++) s+=x;
	}
	
	LL ans=0;
	for(int i=1;i<=m/2;i++){
		if(s[i]!=s[m+1-i]) ans++;
	}
	printf("%d",ans);
	return 0;
}
