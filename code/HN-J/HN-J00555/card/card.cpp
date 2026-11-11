#include<bits/stdc++.h>
using namespace std;
int n,m;
int arr[500005];
int arr1[500005];
int tong[100];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int h=n;
		while(h>1){
			int ans=0;
			for(int j=0;j<h;j++){
				for(int k=0;k<j;k++){
					if(arr[j]==arr[k]){
						while(k<j){
							arr1[k]=0;
							k++;
							ans--;
						}
					}
				}
				arr1[j]=arr[j];
				ans++;
			}
			for(int i=0;i<=ans+2;i++){
				if(arr1[i]>0){
				tong[arr1[i]]++;
				}
			}
			h--;
		}
		for(int i=0;i<=100;i++){
			if(tong[i]>0){
				cout<<tong[i]<<" ";
			}
		}
return 0;
}
