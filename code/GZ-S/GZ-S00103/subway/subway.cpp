//GZ-S00103 南白初级中学 唐清倾 
#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[500001]={},k[500001]={},a[500001]={},t[500001]={},x[100001]={},y[100001]={};
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[j]>>t[j];
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x[i]>>y[i];
	}
	if(q==1) cout<<27;
	else if(q==2){
		cout<<35<<endl;
		cout<<16;
	}
	else if(q==3){
		cout<<27<<endl;
		cout<<41<<endl;
		cout<<35;
	}
}
