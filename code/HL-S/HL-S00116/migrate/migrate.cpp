#include<bits/stdc++.h>
using namespace std;
int c,tim,n[200005],d[200005],a[2000005],ans[2000005],b[200005],f=0,g,len,ul;

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>tim;
	for(int i=0;i<tim;i++){
		cin>>n[i]>>d[i];
		g=f+n[i];
		b[i]=f;
		for(;f<g;f++) cin>>ul;
	}
	
	for(int i=0;i<tim;i++){
	    for(int j=n[i];j>2;j--){
	    	if((n[i]-1)%d[i]!=0) if(d[i]%2==0) ans[i]++;
		}
	}
	return 0;
}
