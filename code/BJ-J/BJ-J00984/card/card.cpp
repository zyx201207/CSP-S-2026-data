#include<iostream>
#include<queue>
using namespace std;
int main(){
	    freopen("card.in","r",stdin);
	    freopen("card.out","w",stdout);
	    int n,m;
		cin>>n>>m;
    	queue<int> q;
		int a[5005];
		int time[3005]={};
		for(int i=1;i<=n;i++)
				cin>>a[i];
		for(int i=1;i<=n;i++){
				int card[5005]={};
				for(int j=i;j<=n;j++){
						card[j]=a[j];
						for(int k=i;k<j;k++){
								if(a[k]==card[j]){
										for(int l=k;l<j;l++) 
												card[l]=0;
										break;
								}
						}
				}
				for(int j=i;j<=n;j++) time[card[j]]++;
		}
		(int i=1;i<=m;i++) cout<<time[i]<<" ";
		return 0; 
}