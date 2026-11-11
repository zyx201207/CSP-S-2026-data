#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005],sum[300005];
int find(int x){
	for(int i=n;i>=1;i--){
		if(a[i]==x) return i;
	}
	return 0;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
    for(int i=1;i<=n;i++){
    	int j=i;
    	while(j<=n){
    		if(find(a[j])==j){
    			sum[a[j]]++;
    			j++;
			}else{
				j=find(a[j]);
			}
			if(j>n) break;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<sum[i]<<' ';
	}
	return 0;
} 
