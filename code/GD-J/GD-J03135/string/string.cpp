#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,a[N],aa[N],l[N],r[N];
char b[N],bb[N];
string s;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		while(a[i]--)s+=b[i]; 
	}
	int i=0,j=s.size()-1,ans=0;
	while(i<=j){
		if(s[i]!=s[j])ans++;
		i++;
		j--;
	}
	cout<<ans;
	return 0;
}
