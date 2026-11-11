#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n=true,m=true,ans=0;
	cin>>n>>m;
	int a[10005];
	for(int i=0;i<=n;i++){
		cin>>a[i];
	}
	for(int i=0;i<=n;i++){
		if (a[i]=false){
			for(int m=i;m<=n;m++){
				a[m]=0;
				a[i+1]=a[i];
			}
		}
		a[i]=false;
	}
	return  0;	
}
