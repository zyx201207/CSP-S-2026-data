#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,m[200005],sum=0,ans=0;
	char c[200005];
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%d %c",&m[i],&c[i]);
		sum+=m[i];
	}
	int l=1,r=n;//ÏòÖÐ¼äÑ¹Ëõ 
	while(sum>1&&l<r){
		int mi=min(m[l],m[r]);
		if(c[l]!=c[r]){
			ans+=mi;
		}
		m[l]-=mi;m[r]-=mi;
		if(m[l]==0)l++;
		if(m[r]==0)r--;
	}
	cout<<ans;
	return 0;
}
