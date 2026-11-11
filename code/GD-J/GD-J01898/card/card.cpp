#include <bits/stdc++.h>
using namespace std;
long long n,i,j,k,y,m,len,l,r,cnt,x,sum;
long long a[500005],mx[500005],ans[500005];
stack <long long> s;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++){
		cin>>a[i];
		mx[a[i]]=i;
	}
	for(i=1;i<=n;i++){
		sum-=ans[a[i]];
		ans[a[i]]=i-sum;
		if(i<mx[a[i]]){
			sum+=ans[a[i]];
		}
	}
	for(i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
