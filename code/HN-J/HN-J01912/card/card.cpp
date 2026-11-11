#include<bits/stdc++.h>
using namespace std;
int run[5000005],ans[5000005];
int isin(int k,int len){
	for(int i=1;i<=len;i++){
		if(run[i]==k) return i;
	}
	return 0;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,a[500005];
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	for(int t=1;t<=n;t++){
		int j=t;
		for(int i=t;i<=n;i++){
			if(isin(a[i],j)){
				for(int k=j;k>isin(a[i],j);k--){
					run[k]=0;
					j--;
				}
			}
			else{
					run[j]=a[i];
					j++;		
			}
			for(int k=t;k<j;k++){
				ans[run[k]]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
			cout<<ans[i]<<' ';
	}
	return 0;
}
