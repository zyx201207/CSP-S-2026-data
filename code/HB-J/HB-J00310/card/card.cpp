#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,a[1500005]={},b[300001]={};
	cin>>n>>m;
	for(int i=1;i<=n;++) cin>>a[i];
	for(int i=1;i<=n;i++){
		int h=1,t=n;
		for(int j=i;j<=n;j++){
			int flag=0;
			for(int k=j+1;k<=n;k++){
				if(a[j]==a[k]){
					t=k,h++;
					a[k]=a[j];
					flag=1;
				}
			}
			if(!flag){
				t++,k++;
				a[k]=a[j];
			}
		}
		for(int j=h;j<=t;j++){
			if(a[j]==i){
				b[i]++;
				break;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	return 0;
}
