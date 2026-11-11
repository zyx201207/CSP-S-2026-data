#include<iostream>
using namespace std;
const int N=10001;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
long long n,m,a[N],b[N]={0},c[N]={0};
cin>>n>>m;
for(int i=1;i<=n;i++){
	cin>>a[i];
}
for(int i=1;i<=n;i++){
	for(int k=i;k<=n;k++){
		if(c[a[k]]==1){
			for(int l=1;l<=n;l++){
				c[a[l]]=0;
			}
			c[a[k]]=1;
		}else{
			c[a[k]]=1;
		}
	}
	for(int j=1;j<=m;j++){
		b[j]+=c[j];
	}
	for(int l=1;l<=n;l++){
		c[a[l]]=0;
	}
}
for(int i=1;i<=m;i++){
	cout<<b[i]<<" ";
}
}
