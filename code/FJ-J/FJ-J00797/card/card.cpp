#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[555555],b[333333],c[333333]={0};
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){	
			for(int j=i;j<=n;j++){
				c[a[j]]++;
				for(int k=i;k<j;k++){
					if(a[j]==a[k] && b[a[k]]!=0){
						for(int l=k;l<j;l++){
							b[a[l]]=0;
							if(c[a[l]]!=0){
								c[a[l]]--;	
							}	
					}
				}
			}
			b[a[j]]=1;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
	return 0;
}
