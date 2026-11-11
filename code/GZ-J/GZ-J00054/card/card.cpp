//GZ-J00054 ÀÔ–°∫≠ 
#include<bits/stdc++.h>
using namespace std;
int a[500005],t[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	bool f=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<a[i-1]){
			f=0;
		}
		t[a[i]]=i;
	}
	if(f){
		for(int i=1;i<=m;i++) cout<<t[i]<<" ";
	}
	else{
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[j]==a[i]){
					for(int k=i+1;k<j;k++){
						t[a[k]]--;
					}
				}
			} 
		}
		for(int i=1;i<=m;i++) cout<<t[i]<<" ";
	}
	return 0;
} 
