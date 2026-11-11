#include<bits/stdc++.h>
using namespace std;
int n,m,a[100000000],ans[100000000]={0},line[100000000]={0},t,sum=0;
int main(){
//	freopen("card.in","r",stdin);
//	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i-1;j<n;j++){
			t=0;
			while(line[t]!=0){
				if(line[t]==a[j]){
					while(line[t]!=0){
						line[t]=0;
						sum--;
						t++;
					}
				}
				t++;
			}
			line[sum]=a[j];
			sum++;
		}
		for(int j=0;j<=sum;j++){
			ans[line[j]]++;
			line[j]=0;
		}
		sum=0;
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
