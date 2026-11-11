//GZ-J00490 遵义市第十二中学 黄正垚
#include <bits/stdc++.h>
using namespace std;
int a[1004],b[1004];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int m,n;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		a[i]=1;
		b[i]++;
		for(int j=1;j<i;j++){
			if(a[j]==a[i]){
				for(int k=j;k<i;k++){
					a[k]=0;
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			
		}
	}
	return 0;
}

