#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,len,t;
int a[500005],ans[300005],s[300005];
bool f(int x){
	for (int k=1;k<=len;k++){
		if (s[k]==x){
			t=k;
			return false;
		}
	}
	return true;
}
void q(){
	for (int k=t-1;k<=len;k++){
		s[k]=0;
	}
	len=t;
	return;
}
void p(){
	for (int j=1;j<=len;j++){
		ans[s[j]]++;
	}
	return;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	for (int i=1;i<=n;i++){
		for (int j=i;j<=n;j++){
			if (f(a[j])){
				s[++len]=a[j];
			}
			else{
				q();
			}
		}
		p();
	}
	for (int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
