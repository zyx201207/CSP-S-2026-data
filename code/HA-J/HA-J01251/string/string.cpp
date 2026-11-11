#include<bits/stdc++.h>
using namespace std;
long long n,m,l=0;
string ans;
string v;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>m>>v;
		for(int j=l;j<l+m;++j){
			ans[j]=v[0];
		}
		l+=m;
	}
	int sum=0;
	for(int i=0;i<(l+1)/2;++i){
		if(ans[i]!=ans[l+1-i])++sum;
		if(ans[i+1]==ans[i]&&ans[l+1-i]==ans[l-i])--sum;
	}
	cout<<sum;
}
