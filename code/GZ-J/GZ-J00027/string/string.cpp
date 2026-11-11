//GZ-J0027 张蔚远 贵阳白云区华师一学校 
#include<bits/stdc++.h>
using namespace std;
int n=0,ln=0,ans=0;
string s="";
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int a;
		char b;
		cin>>a>>b;
		for(int j=1;j<=a;j++){
			s+=b;
		} 
	}
	ln=s.size();
	for(int l=0,r=ln;l<=r;l++,r--){
		if(s[l]!=s[r]){
			ans++;
		}
	}
	printf("%d",ans);
	return 0;
} 
