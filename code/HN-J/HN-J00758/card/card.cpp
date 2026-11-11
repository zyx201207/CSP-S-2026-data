#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005],b[200005],B[200005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=n;i>=1;i--){
		if(b[a[i]]>0){
			for(int j=i;j<=n;j++){
				B[j]++,b[j]=0;
			}
		}
		B[a[i]]++;
	}
	for(int i=1;i<=m;i++){
		cout<<B[i]<<' ';
	}
	return 0;
}
