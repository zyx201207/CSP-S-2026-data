#include <bits/stdc++.h>
using namespace std;
long long n,ans=0;//n<=200000
struct huiwens{
	long long a;
	char c;
}S[200001];
string s="";
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for (int i=1;i<=n;i++){
		cin >> S[i].a >> S[i].c;
		for (int j=1;j<=S[i].a;j++){
			s+=S[j].c;
		}
	}long long l=s.size();
	for (int i=0;i<l/2+1;i++){
		if (s[i]!=s[l-i+1]){
			ans++;
		}
	}cout << ans << endl;
	return 0;
}
