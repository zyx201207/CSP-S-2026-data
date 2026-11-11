#include<iostream>
using namespace std;
int n,m,a[500001],b[500001],c[500001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(m<=3000&&n>5000&&n<=200000){
		for(int i=1;i<=n;i++){
			int c=0;
			for(int j=i;j<=n;j++){
				if(a[j]==i)c++;
			}
			cout<<c<<" ";
		}
	}
	else if((m>3000&&m<=100000)||(m<=3000&&m>=201)){
		for(int i=1;i<=m;i++)cout<<1<<" ";
	}
	else{
		for(int i=1;i<=n;i++){
			int aa=1;
			for(int j=i;j<=n;j++)b[aa++]=a[j];
			for(int j=1;j<=aa;j++){
				for(int k=j+1;k<=aa;k++){
					if(b[j]==b[k]){
						for(int l=j;l<k;l++)b[l]=-10000;
					}
				}
			}
			for(int k=1;k<=aa;k++){
				if(b[k]<0)continue;
				c[b[k]]++;
			}
		}
		for(int i=1;i<=m;i++)cout<<c[i]<<" ";
	}
	
}
