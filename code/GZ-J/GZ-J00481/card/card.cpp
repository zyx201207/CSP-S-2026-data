//GZ-J00481 遵义市第十九中学 刁奕杰 
#include<bits/stdc++.h>
using namespace std;
int n,m;
	int a[500004];
	int b[300004]={0};
	int num[300004]={0};
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int k=1;k<=n;k++){
		for(int i=k;i<=n;i++){
			if(b[a[i]]==1){
				for(int j=a[i]+1;j<=m;j++){
					b[j]=0;
				}
			}else{
				b[a[i]]++;
			}
		}
		for(int j=1;j<=m;j++){
			if(b[j]==1) num[j]++;
			b[j]=0;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<num[i]<<' ';
	}
	return 0;
}

