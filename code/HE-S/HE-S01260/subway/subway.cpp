#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q,m1[500000],i,r,min;
	cin>>c>>n>>m>>d>>q;
	for(int i1=1;i1<=m;i1++){
		cin>>m1[i1];
	}
	for(int x=1;x<m;x++){
		if(m1[x]<m1[x+1]){
			m1[x]=min;
			m1[x]=m1[x+1];
			m1[x+1]=min;
		}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
}
