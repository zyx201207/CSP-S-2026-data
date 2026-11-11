#include<bits/stdc++.h>
using namespace std;
long long n,m,x,a[1000100],ans,c[300100];
int main(){
	//freopen("card.in","r",stdin);
	//freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int b[100100]={0};
		bool f[1001]={0};
		x=0;
		for(int j=i;j<=n;j++){
			if(f[a[j]]==1){
				while(b[x]!=a[j]){
					f[b[x]]=0;
					x--;
				}
			}else{
				x++;
				b[x]=a[j];
				f[a[j]]=1;
			}
		}
		for(int k=1;k<=m;k++){
			if(f[k]==1){
				c[k]++;
			}
		}
		//cout<<x<<endl;
		//for(int i=1;i<=x;i++){
			//cout<<b[i]<<" ";
		//} 
		//cout<<endl;
	}
	for(int k=1;k<=m;k++){
		cout<<c[k]<<" ";
	}
	return 0;
}
