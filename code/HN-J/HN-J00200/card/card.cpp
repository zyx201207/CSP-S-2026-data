#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int ans[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	if(m<=2){
		for(int i=1;i<=n;i++){
			cin>>a[i];
			ans[a[i]]++;
		}
		if(a[n]==1){
			cout<<n<<" "<<ans[2];
		}
		else{
			cout<<ans[1]<<" "<<n;
		}
	}
	else{
		for(int i=1;i<=n;i++){
			cin>>a[i];
			ans[a[i]]++;
		}
		int sum=0;
		for(int i=1;i<=m;i++){
			sum+=ans[i];
			cout<<sum<<" ";
		}
	}
}
