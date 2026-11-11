#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	char a[200005];
	int aa=0,n[200005],b,c=0,i=0;
	cin>>b;
	for(;i<b;i++){
	cin>>n[i]>>a[i];
	c+=n[i];
}
	i--;
	for(int k=0,j=0,h=0,m=0;k*2<=c;k++){
	if(j>n[i]){
	j-=n[i];
	i--;
	}
	if(h>n[m]){
	h-=n[m];
	m++;
	}
	if(a[m]!=a[i])aa++;
	j++;
	h++;
	}
	
	cout<<aa;
	return 0;
}
