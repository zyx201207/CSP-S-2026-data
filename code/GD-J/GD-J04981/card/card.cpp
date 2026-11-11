#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[300005],ans[3000005],k,cnt;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[a[i]]++;
	}
	if(m==1){
		cout<<n;
	}
	else{
		ans[1]=b[1];
		ans[2]=b[2];
		ans[a[n]]=b[a[n]];
		cout<<ans[1]<<' '<<ans[2];
	}
	return 0;
} 
