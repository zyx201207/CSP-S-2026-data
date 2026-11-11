#include<bits/stdc++.h>
using namespace std;
int n,m,a[100005],b[100005],c[100005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i<=n;i++){
		cin >> a[i];		
	}
	for(int i = 1;i<=n;i++){
		for(int x = 1;x<=n;x++){
			b[x]=0;
		}
		for(int j= i;j<=n;j++){
			b[a[j]]++;
			if(b[a[j]]>1){
				bool y=0;
				for(int x = 1;x<=n;x++){
					if(a[x]==a[j]){
						y=1;
					}
					if(y==1){
						b[a[x]]--;
					}
				}
				
			}
			b[a[j]]=1;
		}
		for(int i = 1;i<=m;i++){
			if(b[i]!=0){
				c[i]+=1;
			}
		}
	}
	for(int i = 1;i<=m;i++){
		cout<<c[i]<<" ";
	}
}
