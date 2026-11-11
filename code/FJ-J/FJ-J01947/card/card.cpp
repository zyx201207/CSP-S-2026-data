#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005],nt[500005],isa[300005],ans[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		isa[a[i]]=i;
	} 
	for(int i=n;i>=1;i--){
		nt[i]=isa[a[i]];
	}
	long long lbj=1;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(nt[j]!=0) j=nt[j];
			ans[a[j]]++;
		}
	}
	for(int i=1;i<=m;i++)  cout<<ans[i]<<" ";
	return 0;
}
