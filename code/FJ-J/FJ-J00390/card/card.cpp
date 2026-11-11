#include<bits/stdc++.h>//T4
using namespace std;
int n,m,hh1,hh2;
int a[500001];
inline int rd(){
	int k=0,q=1;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-')q=-1;
		c=getchar();
	}while(isdigit(c)){
		k*=10,k+=c-48,c=getchar();
	}
	return k*q;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	n=rd(),m=rd();
	for(int i=1;i<=n;++i){
		a[i]=rd();
	}if(m>2){
		for(int i=1;i<=m;i++){
			cout<<1<<" ";
		}
	}else{
		for(int i=1;i<=n;++i){
			if(a[i]==1&&a[n]==2){
				hh1++,hh2++;
			}else if(a[i]==2&&a[n]==2){
				hh2++;
			}else if(a[i]==2&&a[n]==1){
				hh1++,hh2++;
			}else if(a[i]==1&&a[n]==1){
				hh1++;
			}
		}cout<<hh1<<" "<<hh2;
	}
	return 0;
}
