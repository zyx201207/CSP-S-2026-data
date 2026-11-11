#include<bits/stdc++.h>
using namespace std;
int n,m,a1[200010];
string a[200010];
void check(int i1,int z){
	int z1=1,z2=z;
	while(z2!=1){
		a[i1][z1]=z2%2;
		z2/2;
		z1++;
	}
} 
void cot(int z){
	
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int z;
		cin>>z;
		a1[i]=z;
		check(i,z);
	}
	iif(n<=2000&&m=1){
		int max1=-1,max2;
		for(int i=1;i<=n;i++){
			max(max1,a1[i]);
			if(max1==a1[i]) max2=i;
		}
		cout<<max2;
	}
	return 0;
}
