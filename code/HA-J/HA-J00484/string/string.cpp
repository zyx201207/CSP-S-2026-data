#include<bits/stdc++.h>
using namespace std;
#define LL long long
LL n;
bool vis[200010];
char c[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	LL ans=0;
	LL p=0;
	LL s=0;
	for(int i=0;i<n;i++){
		LL x;
		cin>>x>>c[i];
		if(i==0) p=x;
		if(i>0){
			if(c[i]!=c[0]) ans+=x;
		}
		s+=x;
	}
	if(ans==0){
		cout<<0;
		return 0;
	}
	if(n%2==1&&p<s/2+1) ans--;
	cout<<ans;
	return 0;
}
