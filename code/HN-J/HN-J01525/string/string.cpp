#include <bits/stdc++.h>
using namespace std;
string s,s1;
long long a[200005],ans;
int n;
char x,c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c;
		s1+=c;
	}
	s="#";
	for(int i=1;i<=n;i++)
		for(long long j=1;j<=a[i];j++) s=s+s1[i-1];
	for(long long i=1,j=s.size()-1;i<=j;i++,j--)
		if(s[i]!=s[j]) ans++;
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
