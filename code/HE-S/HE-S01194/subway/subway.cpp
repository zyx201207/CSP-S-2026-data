#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int a,b,c,d,e;
	cin>>a>>b>>c>>d>>e;
	long long q[10005];
	for(int i=0;i<c;i++){
		cin>>q[i];
	}
	long long lj[10005],w,z;
	for(int i=0;i<b;i++){
		cin>>w;
		for(int j=0;j<w;j++){
			cin>>lj[j];
			cin>>z;
		}
	}
	for(int i=0;i<e;i++){
		int o,p;
		cin>>o>>p;
		cout<<z*(p-o+2)+q[o]+q[p]<<endl;
	}
} 
