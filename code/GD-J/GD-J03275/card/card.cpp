#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int m,n,ipt,a[300003],tem[300003]={0},res[300003]={0};
	cin>>m>>n;
	for(int i=0;i<m;i++){
		cin>>a[i];
	}
	for(int i=0;i<m;i++){
		memset(tem,0,sizeof(tem));
		for(int j=i+1;j<m;j++){
			if(a[j]==a[j-1]){
				tem[j-1]=1;
			}
		}
		for(int j=i;j<m;j++){
			if(tem[j]==0){
				res[a[j]]++;
			}
		}
	}
	for(int i=0;i<n;i++){
		cout<<res[i]<<" ";
	}
	return 0;
}
