#include<bits/stdc++.h>
using namespace std;
int n,m,a[500007],mn[300007],k,cnt[300007],ans[500007];
bool f;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		k=0;
		for(int j=i;j<=n;j++){
			f=0;
			for(int s=1;s<=k;s++){
				if(ans[s]==a[j]){
					f=1;
					k=s;
					break;
				}
			}
			if(f==0){
				k++;
				ans[k]=a[j];
			}
		}
		for(int j=1;j<=k;j++){
			cnt[ans[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<endl;
	}
	return 0; 
}
