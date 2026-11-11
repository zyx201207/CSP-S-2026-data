#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string S;
ll N;
ll ans=0;
char c[200005];
ll a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>N;
	for(int i=1;i<=N;i++){
		cin>>a[i]>>c[i];
		for(int i=1;i<=a[i];i++){
			S+=c[i];
		}
	}
	for(int i=0;i<S.size();i++){
		if(S[i]!=S[S.size()-i-1]) ans++;
	}
	cout<<ans;
	return 0;
}
