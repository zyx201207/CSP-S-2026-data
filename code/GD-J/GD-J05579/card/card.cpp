#include<bits/stdc++.h>
using namespace std;
int n,m,a[100005];
int main(){
//	freopen("card.in","r",stdin);
//	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i = 0; i<n; i++){
		cin>>a[i];
	}
	if(m==1){
		if(n%2==0){
			cout<<0;
			return 0;
		}
		if(n%2!=0){
			cout<<1;
			return 0;
		}
	}
	if(m==2){
		cout<<2<<2;
		return 0;
	}
	int ans[100001];
	for(int i = 0;i<n;i++){
		int dachu[100001]={0};
		for(int j = i;j<n;j++){
			dachu[j]=a[j];
			for(int k = i;k<=j;k++){
				if(dachu[j]==dachu[k]){
					for(int f = k;f<j;f++){
						dachu[f]=0;
					}
				}
			}
		}
		for(int j = i;j<n;j++){
			if(dachu[j]==i){
				ans[i]++;
			}
		}
	}
	for(int i = 0;i<m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
} 
