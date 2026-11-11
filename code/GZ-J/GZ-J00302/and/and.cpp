//GZ-J00302 遵义市第四中学 马跃腾 
#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005];
int yu(int a,int b){
	int aa[50],bb[50],i=1,num,m=1;
	while(a>0){
		aa[i]=a%2;
		a/=2;
	}
	while(b>0){
		bb[i]=b%2;
		b/=2;
	}
	for(int j=1;j<32;j++){
		if(aa[j]==1&&bb[j]==1){
			num+=m;
		}
		m*=2;
	}
	return num;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	cout<<yu(n,m);
	return 0;
}
