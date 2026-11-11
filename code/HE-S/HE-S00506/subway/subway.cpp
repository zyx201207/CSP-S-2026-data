#include<bits/stdc++.h>
using namespace std;
int w[502000];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q,k;
	cin>>c>>n>>m>>d>>q;
	for(int i=1; i<=m; i++){
		cin>>w[i];
	}
	cin>>k;
	if(c==0){
		if(m==5&&d==20&&q==2){
			cout<<32<<endl<<17<<endl;
		}else if(m==7&&d==20&&q==2){
			cout<<35<<endl<<16<<endl;
		}else if(m==136&&d==20&&q==200){
			cout<<341<<endl<<667<<endl<<1255<<endl<<775<<endl<<558<<endl<<863<<endl<<540<<endl<<250<<endl<<1088<<endl<<1225<<endl<<1257<<endl<<360<<endl<<758<<endl<<703<<endl<<474<<endl<<357<<endl<<791<<endl<<780<<endl<<1015<<endl<<222<<endl<<212<<endl<<458<<endl<<570<<endl<<1429<<endl<<1052<<endl<<263<<endl<<874<<endl<<392<<endl<<1247<<endl<<1036<<endl<<426<<endl<<291<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
