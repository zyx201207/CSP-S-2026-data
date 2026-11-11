#include <bits/stdc++.h>
using namespace std;
long long int n,m;
long long int a[5000005],c[100005];
int main(){
	freopen ("card.in","r",stdin);
	freopen ("card.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++) cin>>a[i];
	for (int l=1;l<=n;l++){
		long long int b[500005];
	for (int i=l;i<=n;i++){
		
		b[i]=a[i];
		for (int j=l;j<i;j++){
			if (b[j]==b[i]){
				for (int p=j;p<i;p++){
					b[p]=-1;
				}
				break;
			}
		}
	}
	for (int i=l;i<=n;i++){
		if (b[i]!=0) c[b[i]]++;
	} 
	
	}
	for (int i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
	return 0;
}
