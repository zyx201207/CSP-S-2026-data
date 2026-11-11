#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,ans=0;
	int a[n]={};
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		}
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			if(a[j]<a[j+1]){
				int x=a[j];
				a[j]=a[j+1];
				a[j+1]=x;	
			}
		}
	}
	ans=a[0];
	for(int i=1;i<m;i++){
		ans=ans and a[i];
	}	
	cout<<ans;
	return 0;
}

