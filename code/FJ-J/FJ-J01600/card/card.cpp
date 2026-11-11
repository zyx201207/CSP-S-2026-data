#include<bits/stdc++.h>
using namespace std;
int n,m,i,j,k,a[500010],hua[200010],b[500010],huaa[500010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++){
		cin>>a[i];
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			hua[j]=0;
		}
		for(j=i;j<=n;j++){
			b[j]=a[j];
		}
		for(j=i;j<=n;j++){
			if(hua[a[j]]==0){
				hua[a[j]]=j;
			}else{
				for(k=hua[a[j]];k<j;k++){
					hua[b[k]]=0;
					b[k]=0;
				}
				hua[a[j]]=j;
			}
		}
		for(j=i;j<=n;j++){
			huaa[b[j]]++;
		}
	}
	for(i=1;i<=m;i++){
		cout<<huaa[i]<<" ";
	}
	return 0;
}

