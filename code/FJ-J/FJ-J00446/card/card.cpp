#include<iostream>
using namespace std;
int last[300010],n,m,a[500010];
int ans[300010];
bool sim=1;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		last[a[i]]=i;
		if(a[i]<a[i-1]) sim=0;
	}
	if(sim==0){
		for(int i=1;i<=n;i++){
			int k=i;
			while(k<=n){
				ans[a[k]]++;
				k=last[a[k]]+1;
			}
		}
		for(int i=1;i<=m;i++){
			cout<<ans[i]<<" ";
		}
	}
	else{
		for(int i=1;i<=n;i++){
			ans[a[i]]++;
		}
		for(int i=1;i<=m;i++){
			ans[i]+=ans[i-1];
			cout<<ans[i]<<" ";
		}
	}
	
	return 0;
}
