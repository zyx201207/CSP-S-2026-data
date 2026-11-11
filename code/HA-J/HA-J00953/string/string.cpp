#include <bits/stdc++.h>
using namespace std;
int n,a[200005];
char b[200005];
string s1,s2;
long long f=1,cnt,ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	while(f<=n){
		for(int i=1;i<=a[f];i++){
			s1+=b[f];
		}
		f++;
	}
	long long m=s1.size();
	for(int i=m-1;i>=0;i--){
		s2[++cnt]=s1[i];
	}
	for(int i=0;i<=m-1;i++){
		if(s1[i]!=s2[i]){
			ans++;
		}
	}
	cout<<ans-1;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

