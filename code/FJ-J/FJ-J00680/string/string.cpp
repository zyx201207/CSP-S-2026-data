#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int N=2e5+5;
struct node{
	int num;
	char c;
}a[N];
int n,tot;
string s;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].num>>a[i].c;
		tot+=a[i].num;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i].num;j++){
			s+=a[i].c;
		}
	}
	s=' '+s;
	int i=1,j=tot,ans=0;
	while(i<=j){
		if(s[i]!=s[j])ans++;
		i++,j--;
	}
	cout<<ans<<endl;
	return 0;
}
