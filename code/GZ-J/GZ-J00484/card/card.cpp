#include<bits/stdc++.h>
using namespace std;
int n,m,a1[500005],a[500005],sum[3000005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){

		for(int j=i;j<n;j++){
			a1[j]=a[j];
			for(int y=i;y<j;y++){
				if(a1[y]==a[j]){
					for(int x=i;x<j;x++){
					a1[x]=0;
				}
				}
			}

		}
		for(int j=i;j<n;j++){
			sum[a1[j]]++;
		}
	}
	for(int i=1;i<300005;i++){
		if(sum[i]>0){
			cout<<sum[i]<<" ";
		}
	}
	return 0;
}
