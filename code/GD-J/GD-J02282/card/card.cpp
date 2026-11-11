#include<bits/stdc++.h>
using namespace std;
int n,m,ans,cnt;
int a[500005],c[500005]; 
int main(){
	freopen(card.in,"r",stdin);
	freopen(card.out,"w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		ans=0;
		int b[500005]={}; 
		for(int j=i;j<=n;j++){
			bool flag=0;
			for(int k=1;k<=ans;k++){
				if(flag==1){
					b[k]=-1;
					ans--;
				} 
				if(b[k]==a[j]){
					flag=1;
					b[k]=-1;
					ans--;
				}
			}
			ans++;
		    b[ans]=a[j];
		}
		for(int j=1;j<=m;j++){
			for(int k=1;k<=ans;k++){
				if(b[k]==j){
					c[j]++;
					break;
				}
			}
		}
	}
	for(int i=1;i<=m;i++) cout<<c[i]<<" ";
	return 0;
}

