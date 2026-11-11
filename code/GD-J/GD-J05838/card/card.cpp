#include <bits/stdc++.h>
using namespace std;
int n,m,a[1000007],b[1000007],top,c[10000007];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			for(int k=1;k<=top;k++){
				if(a[j]==b[k]){
					top=k-1;
					break;
				}
			}
			top++;
			b[top]=a[j];
		}
		for(int j=1;j<=top;j++){
			//cout<<b[j]<<" ";
			c[b[j]]++;
		}
		//cout<<endl;
		top=0;
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
	return 0;
}
