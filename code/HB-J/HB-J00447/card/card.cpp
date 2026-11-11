#include<bits/stdc++.h>
using namespace std;
int n,m,a[100009]={0},b[100009]={0},ans[1000009]={0};

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(b[a[j]]==1){
				for(int k=j-1;;k--){
					if(b[a[k]]>0)b[a[k]]--;
					
					if(a[k]==a[j])break;
				}
			}
			b[a[j]]++;
		}
		for(int k=1;k<=m;k++){
			ans[k]+=b[k];
			b[k]=0;
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0;
}
