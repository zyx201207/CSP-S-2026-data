#include<bits/stdc++.h>
using namespace std;
int a[200008],b[200008],c[200008];
int main(){
	freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int flag=0;
	for(int i=0;i<n;i++){
		int b[200008]={0};
		for(int j=i;j<n;j++) b[a[j]]++;
		for(int j=i;j<n;j++){
			b[a[j]]--;
			if(flag==1){
				c[a[j]]++;
				flag=0;
			} 
			if(b[a[j]]==0) {
				flag=1;
			}
			else flag=0;
		}
	}
	c[a[n-1]]=n;
	for(int i=1;i<=m;i++) cout<<c[i]<<" ";
	return 0;
} 
