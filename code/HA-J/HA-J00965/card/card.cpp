#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[500005],d=1,s[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];	
	}
	for(int i=1;i<=n;i++){
		for(int k=i;k<=n;k++){
			b[k]=a[k];
			for(int j=d;j<k;j++){
				if(b[j]==a[k]){
					d=k;
					break;
				}
			}	
		}
		for(int j=d;j<=n;j++){
			s[b[j]]++;
			cout<<b[j];
		}
	}
	for(int i=1;i<=m;i++){
		cout<<s[i]<<" ";
	}
	return 0;

}
