#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int a[150005],ans[100005]={},n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int j=0;j<n;j++){
		int b[150005]={};
		bool c[150005]={};
		int number=0;
		for(int i=j;i<n;i++){
			
			if(c[a[i]]==0){
				b[number++]=a[i];
				c[a[i]]=1;
			}
			else{
				while(b[number-1]!=a[i]){
					c[b[number-1]]=0;
					b[number-1]=0;
					number--;
				}
			}
		}
		for(int i=0;i<number;i++){
			ans[b[i]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
