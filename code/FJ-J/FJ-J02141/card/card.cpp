#include<bits/stdc++.h>
using namespace std;

const int N=5e5+10;

int a[N];
int Tong[N];
int ans_t[N];

int main(){
	
	freopen("card.in","w",stdin);
	freopen("card.out","r",stdout);
	
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++)
	    cin>>a[i];
	    
	for(int i=1;i<=n;i++){
		Tong[1]=a[1];
		for(int j=2;j<=n;j++){
			for(int k=1;k<=j-1;k++){
				if(Tong[k]==a[j]){
					for(int r=k;r<=j-1;r++)
				        Tong[r]=0;
				    Tong[k]=a[j];
				}  
			}
			Tong[j]=a[j];
		}
		for(int j=1;j<=n;j++)
			ans_t[Tong[j]]++;
		for(int j=1;j<=n;j++)
			cout<<ans_t[j]<<" ";
	}
	return 0;
}





