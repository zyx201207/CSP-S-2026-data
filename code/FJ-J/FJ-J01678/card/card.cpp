#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int sum1=0,sum2=0,a[10]={0},b[10]={0};
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	for(int i=1;i<=n;i++){
		b[10]={0};
		for(int j=i;j<=n;j++){
		
			for(int t=i;t<j;t++){
				if(b[t]==a[j]){
					for(int k=t;k<j;k++){
						b[k]=0;
					}
					break;
				}
			}
				b[j]=a[j];
		}
		for(int j=i;j<=n;j++){
			if(b[j]==1){
				sum1++;
			}
			else if(b[j]==2){
				sum2++;
				
			}
		}
	}
	cout<<sum1<<" "<<sum2;
	return 0;
}
