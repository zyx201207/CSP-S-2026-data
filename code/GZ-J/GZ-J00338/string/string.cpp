//GZ-J00338 贵阳市第三实验中学 张普博 
#include<bits/stdc++.h>
using namespace std;
long long n,ans,k=1,su;
long long m[200005];
char c[200005];
char s[100000000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>m[i]>>c[i];
		for(k;k<=su+m[i];k++){
			s[k]=c[i];
		}
		su+=m[i];
	}
	for(int i=1,j=su;i<=j;i++,j--){
		if(s[i]!=s[j]) ans++;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
