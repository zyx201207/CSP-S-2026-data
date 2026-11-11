#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],s=1,ans=0,k;
bool flag=true;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	k=m;
	int b[m][n];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(a[j]==i){
				b[i][s]=j;
				s++;
			}
		}
		s=1;
	}
	while(m--){
		for(int i=1;i<=n;i++){
			flag=true;
			if(b[k-m][s]<a[i]){
				s++;
			}
			for(int j=i;j<=n;j++){
				if(b[k-m][s]>b[j][1]){
					for(int r=1;r<n;r++){
						if(b[j][r]>b[i][s]){
							flag=false;
							break;
						} 
					}
					if(!flag){
						break;
					}
				}
			}
			if(flag){
				ans++;
			}	
		}
		cout<<ans<<" ";
	}
	return 0;
}
