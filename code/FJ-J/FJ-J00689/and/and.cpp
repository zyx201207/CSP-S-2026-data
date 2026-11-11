#include<bits/stdc++.h>
using namespace std;
int a[200005],b[200005],maxx;
int n,m,z;
void cnt(int j,int k,int y){
	if(y==m){
		maxx=max(maxx,k);
		return;
	}for(int i=j+1;i<=n;i++){
		k=k&i;
		y++;
		cnt(i,k,y);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	if(m==1){
		cout<<a[n];
		return 0;
	}
	if(m==n){
		z=a[1];
		for(int i=2;i<=n;i++){
			z=z&a[i];
		}cout<<z;
		return 0;
	}if(m==n-1){
		z=a[2];
		for(int i=3;i<=n;i++){
			z=z&a[i];
		}cout<<z;
		return 0;
	}if(m==2){
		z=a[n];
		z=z&a[n-1];
		cout<<z;
		return 0;
	}for(int i=1;i<=n;i++){
		cnt(i,a[i],0);
	}cout<<maxx;
}
