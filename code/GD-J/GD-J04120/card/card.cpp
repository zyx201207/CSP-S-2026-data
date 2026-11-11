#include<bits/stdc++.h>
using namespace std;
const int M=3*1e5+5;
int n,m,ans[M],num[M],a[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		num[a[i]]++;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(num[a[j]]){
				int k=j+1,c=0,ne=j;
				while(k<=n){
					if(a[k]==a[j]){
						c+=1;
						ne=k;
					}
					k++;
				}
				ans[a[j]]++;
				j=ne;
			}
		} 
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	} 
	fclose(stdin);
	fclose(stdout);
	return 0;
}
