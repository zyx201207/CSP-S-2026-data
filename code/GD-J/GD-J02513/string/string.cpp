#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
int n,ans;
int v[N];
char s[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	//ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>v[i]>>s[i];
	}
	int l=1,r=n;
	while(l!=r){
		int sum=min(v[l],v[r]);
		v[l]-=sum;
		v[r]-=sum;
		ans+=((s[l]!=s[r])*sum);
		if(v[l]>v[r]){
			r--;
		}
		else{
			l++;
		}
	}
	cout<<ans;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
