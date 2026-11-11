#include<bits/stdc++.h>
using namespace std;
long long n,num[200005],ans,l,m,r;
char k[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	l=1;
	r=n;
	for(int i=1;i<=n;i++) cin>>num[i]>>k[i];
	while(l<=r){
		m=min(num[l],num[r]);
		if(k[l]!=k[r]) ans+=m;
		if(l!=r){
			num[l]-=m;
			num[r]-=m;
		}
		else num[l]-=m;
		if(num[l]==0) l++;
		if(num[r]==0) r--;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
