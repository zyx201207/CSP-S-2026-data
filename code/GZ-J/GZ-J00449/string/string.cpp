//GZ-J00449 曾嵩 兴义市弘毅中学
#include<bits/stdc++.h>
using namespace std;
const int MAXN=20050;
int n;
int a[MAXN];
long long cnt;
char c[MAXN];
string S;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>c[i];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=a[i];j++)
			S+=c[i];
	//s=reverse(S.begin(),S.end());
	//cout<<S;
	//cin>>S;
	for(size_t i=0;i<S.size()/2;i++)
		if(S[i]!=S[S.size()-1-i])
			cnt++;
	cout<<cnt;
	return 0;
}
