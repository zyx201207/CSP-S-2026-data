#include<bits/stdc++.h>
using namespace std;
int a[10005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int m,n;
	cin>>m>>n;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	int ans=0;
	if(m==n){
		for(int i=1;i<m;i++){
			ans=a[i];
			ans=ans&a[i+1];
		}
	}else{
		for(int i=1;i<=m;i++){
			for(int k=i;k<=m;k++){
				int num=a[k];
				for(int j=1;j<=n;j++){
					num=num&a[j+1];
				}
				if(num>ans){
					ans=num;
				}
			}
		}
	}
	cout<<ans;
	return 0;
} 
