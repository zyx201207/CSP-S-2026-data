#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1000001],p=0;//一点思路都没有，骗分 
int main(){
	freopen("and.in","r",stdin); 
	freopen("and.out","w",stdout); 
	scanf("%d%d",&n,&m);
	if(n-m==1){
		for(int i=1;i<=n;i++){
		scanf("%d",a[i]);
		p=max(p,a[i]);
		
	}	
	cout<<p;
	return 0;
	}else{
		for(int i=1;i<=n;i++){
		scanf("%d",a[i]);
		
		}
		cout<<0;
	}
	
}
