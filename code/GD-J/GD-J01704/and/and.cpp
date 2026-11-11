#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200001],mm; 
string d;
void ss(int i,long long t,int j){
	if(j==m){
		mm=max(mm,t);
		return ;
	}
	if(i==n){
		return ;
	}
	if(j==0){
		ss(i+1,a[i+1],j+1);
	}
	ss(i+1,t,j);
	ss(i+1,t&a[i+1],j+1);
};
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	ss(0,0,0);
	printf("%lld",mm);
	return 0;
}



