#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[500025],m,s[300025],d[300025],f[300035];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	for(int i=n;i>=1;i--){
		d[a[i]]++;
		if(d[a[i]]==2){
			for(int j=i;j<=f[a[i]]-1;j++)
			d[a[j]]--;
		}else
		f[a[i]]=i;
		for(int j=1;j<=m;j++){
		s[j]=s[j]+d[j];
	}
	}
	for(int i=1;i<=m;i++){
		cout<<s[i]<<' ';
	}
	return 0;
}
