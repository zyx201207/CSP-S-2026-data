#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,c=0;
	cin>>n>>m;
	char a[n+1],b[n+1];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<n;j++){
			for(int k=i;k<n;k++){
				if(b[k]=a[j]){
					for(int l=k;l<n;l++){
						b[l]=0;
					}
					b[k]=a[j];
					break;
				}
				else{
					for(int l=n;l>i;l--){
						if(b[l]>0){
							b[l+1]=a[j];
							break;
						}
					break;
					}
				}
			}
		}
		for(int l=i;l<m;l++){
			if(b[l]==i){
				c++;
				break;
			}
		}
		for(int l=i;l<m;l++){
			b[l]=0;
		}
		cout<<c<<" ";
		
	}
	
	return 0;
}
