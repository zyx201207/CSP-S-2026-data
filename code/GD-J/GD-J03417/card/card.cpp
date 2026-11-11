#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	int n,m;
	cin>>n>>m;
	int a[200005],sum[1000000000];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int n1=1;
	while(n1<=n){
		int b[200005]={0};
		int bi=0;
		for(int i=n1;i<=n;i++){
			int find=0;
			for(int j=1;j<=bi;i++){
				if(b[j]==a[i]){
					find=1;
				}
				if(find==1){
					b[j]=0;
					bi--;
				}
			}
			bi++;
			b[bi]=a[i];
			
		}
		for(int i=1;i<=bi;i++){
			sum[(b[i])]++;
		}
		n1++;
	}
	for(int i=1;i<=m;i++){
		cout<<sum[i]<<" ";
	}
		
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}
