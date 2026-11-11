#include<bits/stdc++.h>
using namespace std;
int zz;
long long zc[200005],zb,js;
string ds;
char zm[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>zz;
	for(int z=1;z<=zz;z+=1){
		cin>>zc[z]>>zm[z];
		for(long long x=1;x<=zc[z];x+=1){
			ds=ds+zm[z];
		}
	}
	zb=ds.size();
	for(long long z=0;z<=(zb-1)/2;z+=1){
		if(ds[z]!=ds[zb-z]){
			js++;
		}
	}
	//cout<<ds<<endl;
	cout<<js;
	return 0;
}
