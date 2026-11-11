#include<bits/stdc++.h>
using namespace std;
int n,m,ma,a[200005],tmp;

void pog(int b){
	for(int i=b;i<=max(m,n-b);++i){
	if(i!=b){
	tmp=tmp & a[i];
	}else{
		tmp=a[i];
	}
   }
   
   return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d",&n,&m);
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		
	}
	for(int i=1;i<=n-m;++i){
		pog(i+1);
		cout<<i<<" "<<tmp<<"\n";
		if(tmp>ma){
			ma=tmp;
		}
	}
	cout<<ma<<"\n";

	fclose(stdin);
	fclose(stdout);
	return 0;
}


