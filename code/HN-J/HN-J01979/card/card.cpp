#include<bits/stdc++.h>
using namespace std;
int num[100000000]={0},ans[100000000]={0};
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>num[i];
	}
	int f,r;
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			f=0,r=0;
			for(int l=n;l>j;l--){
				if(num[j]==num[l]){
					f=j;
					r=l;
					j=r;		
					break;		
				}
			}
			ans[num[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
} 
