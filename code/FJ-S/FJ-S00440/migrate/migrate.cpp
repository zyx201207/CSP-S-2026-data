#include<iostream>
using namespace std;
int n,m,a,b;
int k[100001];
int qwe(int z,int l,int k,int sum){
	int l1=l;
	if(l1==0){
		return ++sum;
	}
	for(int i=l1;i>=0;i=i){
		for(int j=1;j<=k;j++){
			l1-=z;
			sum=qwe(z,l1,k,sum);
			l1+=z;
		}
	}
}
int main(){
     freopen("migrate.in","r",stdin);
     freopen("migrate.out","w",stdout);
     cin>>n>>m;
     for(int i=1;i<=m;i++){
     	cin>>a>>b;
     	for(int j=1;j<=a;j++){
     		cin>>k[i];
     	}
    }
        int z=k[2]-k[1];
        z=b/z;
        z=((a-1)%z==0)?(a-1)/z:(a-1)/z+1;
        qwe(z,a,b,0);
     fclose(stdin);
     fclose(stdout);
     return 0;
}
