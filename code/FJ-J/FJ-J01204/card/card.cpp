#include<bits/stdc++.h>
using namespace std;
int x[50005];
int sc[100000];

struct sz{
	int s;
	int z;
};
sz kk[300005];
bool pp(int x,int sl){
	for(int i=0;i<sl;i++){
		if(kk[i].s==x){
			return false;
		}
	}
	return true;
}
int main(){
//	freopen("card.in","r",stdin);
//	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>x[i];
	}
	
	int c[m+1]={0};
	int wz=0;
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			if(pp(sc[j],wz)){
				kk[x[j]].s=1;
				wz+=1;
				sc[wz]=x[j];
				kk[x[j]].z=wz;
			}
			else{
				for(int ij=kk[x[j]].z+1;sc[ij]<wz;ij++){
					sc[ij]=0;
					wz--;
				}
			}
		}
		for(int bs=0;bs<=wz;bs++){
			c[sc[bs]]+=1;
			sc[bs]=0;
		}
	
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
	
	return 0;
}
