#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1000005],b[1000005],c[1000005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			b[a[j]]++;
			if(b[a[j]]==2){
				for(int k=j-1;k>=i;k--){
					if(b[a[k]]-1<0) b[a[k]]=0;
					else b[a[k]]--;
					if(a[k]==a[j]) break;
				}
			}
		}
		for(int j=1;j<=m;j++){
			if(b[j]>0) {
				c[j]++;
			}
			b[j]=0;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
	return 0;
}

