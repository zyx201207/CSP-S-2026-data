#include<bits/stdc++.h>
using namespace std;
#define int long long
int an[200001];
char c[200001];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,last=0,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>an[i]>>c[i];
	for(int i=1,j=n;i<j;i++){
		int x=-last;
		for(j;;j--){
			if(x>=an[i]) break;
			x+=an[j];
			if(c[j]!=c[i]) ans+=an[j];
		}
		last=an[j+1]-x+an[i];
		if(c[j+1]!=c[i]) ans-=an[j+1]-last;
	}
	cout<<ans;
	return 0;
}
