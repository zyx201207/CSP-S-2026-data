#include<bits/stdc++.h>
using namespace std;

int a[100005],t[100005],l[100005];

int main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
	int x=0;
		for(int j=i;j<=n;j++){
			for(int k=0;k<j;k++){
				if(a[j]==l[k]){
					for(int r=1;r<=x;r++){
						if(r==1){
							l[r]==a[j];
						}
						else{
							l[r]==0;
						}
					}
					x=1;
				}
				else{
					x++;
					l[x]=a[j];
				}
			}
		}
		for(int j=1;j<=x;j++){
			t[l[i]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<t[i]<<" ";
	}
}
