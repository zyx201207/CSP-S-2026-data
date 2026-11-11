#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[200005],i,j,ans=0,mi;
char ch[200006];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;++i){
		cin >> a[i] >> ch[i];
	}
	i=1,j=n;
	while(i<j){
		if(ch[i]!=ch[j]){
			mi=min(a[i],a[j]);
			ans+=mi;
			a[i]-=mi;
			a[j]-=mi;
			if(a[i]==0)i++;
			if(a[j]==0)j--;
		}else{
			mi=min(a[i],a[j]);
			a[i]-=mi;
			a[j]-=mi;
			if(a[i]==0)i++;
			if(a[j]==0)j--;
		}
	}
	cout << ans;
	return 0;
}

