#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],ans[200005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.ans","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<n;i++){
		int b[200005]={0},r[200005]={0},t=0;
		for(int j=i;j<n;j++){
			if(r[a[j]]){
				for(int k=j-1;a[k]!=a[j];k--){
					if(k!=j){
						b[k]=0;
						t--;	
					}
				}
			}else{
				r[a[j]]++;
				b[t]=a[j];
				t++;
			}
		}
		for(int i=0;i<n;i++)cout<<b[i]<<" ";
		cout<<endl;
		for(int j=0;j<n;j++){
			ans[b[j]]++;
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" "; 
	return 0;
}

