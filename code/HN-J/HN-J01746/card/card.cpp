#include<bits/stdc++.h>
using namespace std;
int const N=500009;
int a[N]={},ans[N]={},max1=0;
void fmax(int n){
	for(int i=1;i<=n;i++){
		if(max1<a[i])max1=a[i];
	}
} 
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	fmax(n);
	for(int i=1;i<=n;i++){
		int cnt[N]={};
		for(int j=i;j<=n;j++){
			if(cnt[a[j]]==0){
				cnt[j]++;
			}else{
				int k=j;
				while(k--){
					if(a[k]==a[j]){
						break;
					}else{
						cnt[a[k]]--;
					}
				}
			}
		}
		for(int i=1;i<=max1;i++){
			if(cnt[i])ans[i]++;
		}
	}
	for(int i=1;i<=max1;i++){
		if(i==a[n]){
			cout<<n<<" ";
		}else{
			cout<<ans[i]<<" ";
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
