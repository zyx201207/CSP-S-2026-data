#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int arr[n],ans[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
		ans[i]=0;
	}
	for(int i=0;i<n;i++){
		int brr[n],ji[m+1],k=0;
		for(int j=0;j<=m;j++){
			ji[j]=-1;
		}
		for(int j=i;j<n;j++){
			if(ji[arr[j]]!=-1){
				for(int f=0;f<=m;f++){
					if(ji[f]>ji[arr[j]]){
						ji[f]=-1;
					}
				}
				k=ji[arr[j]]+1;
			}else{
				brr[k]=arr[j];
				ji[arr[j]]=k;
				k++;
			}
		}
		for(int j=0;j<k;j++){
			ans[brr[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
