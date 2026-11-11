#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[100000],b[1000000];
int jzh(int x){
	int s=0;
	int i=1;
	while(x!=0){
		s+=(x%2)*i;
		x/=2;
		i*=10;
	}
	return s;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=jzh(a[i]); 
	}
	if(m==2){
		int q=-1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(b[i]&b[j]>q){
					q=b[i]&b[j];
				}
			}
		}
		int u=0,j=1;
		while(q!=0){
			for(int i=1;i<=j;i++){
				j*=2;
			}
			u+=q%10*j;
			q/=10;
		}
		cout<<u;
	}
}
