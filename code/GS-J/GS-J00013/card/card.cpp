#include<bits/stdc++.h>
using namespace std;
int a[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int a1=0,a2=0,id=1;
	while(id<=n){
		int b[6]={};
		for(int i=id;i<=n;i++){
			for(int j=1;j<=i-1;j++){
				if(b[j]==a[i]){
					for(int k=j;k<=n;k++){
						b[k]=0;
					}
					break;
				}
			}
			b[i]=a[i];
		}
		for(int i=1;i<=6;i++){
			if(b[i]==1)a1++;
			else if(b[i]==2)a2++;
		}
		id++;
	}
	cout<<a1<<" "<<a2/2;
	return 0;
}
