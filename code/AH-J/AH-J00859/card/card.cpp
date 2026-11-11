#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,a[100010],now[100010]={0},t[100010];
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			for(int k=i;k<j;k++){
				if(now[k]==a[j]){
					for(int q=k;q<j;q++){
						now[q]=-1;
					}
					break;
				}
			}
			now[j]=a[j];
		}
		for(int k=i;k<n;k++){
			t[now[k]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<t[i]<<" ";
	}
	return 0;
}
