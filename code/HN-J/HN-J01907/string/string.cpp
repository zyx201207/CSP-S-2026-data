#include <bits/stdc++.h>
using namespace std;
long long n,ans,x;
string s,a;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n ;
	for(int i=1;i<=n;i++){
		cin >> x >> a;
		for(int j=1;j<=x;j++){
			s=s+a;
		}
	} 
	int r=s.size(),l=s.size()-1;
	if(r%2==0)r/=2;
	else r=r/2+1;
	for(int i=0;i<r;i++){
		if(s[i]!=s[l])ans++;
//		cout << s[i]<< " " << s[l]<< endl;
		l--;
	}
	cout << ans;
	return 0 ;
}
