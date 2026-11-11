#include<bits/stdc++.h>
using namespace std;
int n,a[200005],nn,aa[200005];
long long len,y,ans;
char s[200005],ss[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	for(int z=1;z<=n;z++){
		cin>>a[z]>>s[z];
		len+=a[z];
	}
	for(int z=1;z<=n;z++){
		if(2*(y+a[z])>len&&2*y<len){
			if(len%2)len--,a[z]--;
			ss[++nn]=s[z];
			aa[nn]=len/2-y;
			ss[++nn]=s[z];
			aa[nn]=a[z]-aa[nn-1];
		}
		else{
			ss[++nn]=s[z];
			aa[nn]=a[z];
		}
		y+=a[z];
	}
	int l=1,r=nn;
	while(l<r){
		long long mn=min(aa[l],aa[r]);
		if(ss[l]!=ss[r])ans+=mn;
		aa[l]-=mn;
		aa[r]-=mn;
		if(!aa[l])l++;
		if(!aa[r])r--;
	}
	cout<<ans;
	return 0;
}
