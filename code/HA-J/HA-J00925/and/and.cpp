#include<bits/stdc++.h>
using namespace std;
int n,m,a[200100];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	int z=a[1];
	if(m==1){
		cout<<z;
		return 0;
	}else if(m==2){
		for(int i=1;i<=m;i+=2){
			if(a[1]=pow(2,i)){
				z=a[2]&a[3];
			}else if(a[2]=pow(2,i)){
				z=a[1]&a[3];
			}else{
				z=a[1]&a[2];
			}
		}
		cout<<z;
		return 0;
	}else if(m==n){
		for(int i=2;i<=n;i++){
			z=z&a[i];
		}
		cout<<z;
		return 0;
	}else{
		for(int i=2;i<=m;i++){
			z=z&a[i];
		}
		cout<<z;
		return 0;	
	}
	return 0;
}
