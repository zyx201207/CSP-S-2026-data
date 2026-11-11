#include<bits/stdc++.h>
using namespace std;
int a[500005],ans[3005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){ 
		int sum=0,b[1000005]={ },c[1000005]={ };
		for(int j=i;j<=n;j++){
			if(c[a[j]]!=0){
				sum=c[a[j]];
			}
			else{
				sum++;
				c[a[j]]=sum;
				b[sum]=a[j];
			}
		}
		for(int j=1;j<=m;j++){
			for(int h=1;h<=sum;h++){
				if(b[h]==j){
					ans[j]++;
					break;
				}
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
