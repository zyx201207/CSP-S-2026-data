#include<bits/stdc++.h>
using namespace std;
int gm,t,c=0,nc=0,mil,nl;//gm√ª”√ 
int n;long long d;
void kskbl(int x,int y){	
	if(x==y){
		nc++;
	}
	for(int i=1;i<=d;i++){
		long long nx=x+i;
		if(nx<=y){
			nl++;
			kskbl(nx,y);
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>gm>>t;
	while(t--){
		cin>>n>>d;
		c=0;
		long long a[2000005];
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=1;i<n;i++) {
			nc=0;
			for(int j=n;j>i;j--){
				kskbl(i,j);
				if(!(nc>2||nc<2))c++
			}
		}cout<<c<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
