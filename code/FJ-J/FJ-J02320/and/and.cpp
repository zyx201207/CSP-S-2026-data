#include <iostream>
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,t=0,x,h;
	std::cin>>n>>m;
	int a[n-1];
	for(int i=0;i<n;i++){std::cin>>a[i];}
	for(int i=0;i<n;i++){
		for(int j=0;j<n-i;j++){
			if(a[j]<a[j+1]){
				x=a[j+1];
				a[j+1]=a[j];
				a[j]=x;
			}
		}
	}h=a[0];
	for(int i=1;i<m;i++){
		h=h&a[i];
	}std::cout<<h;
	return 0;
}

