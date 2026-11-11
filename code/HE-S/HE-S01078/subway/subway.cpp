#include<bits/stdc++.h>
using namespace std;
int a,b,c,d,e,f,g,x[100000005],w,z,z1;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>a>>b>>c>>d>>e;
	for(int i=0;i<c;i++){
		cin>>x[i];
	}
	for(int i=0;i<b;i++){
		cin>>f;
		for(int j=0;j<f*2;j++){
			cin>>g;
			if(j%2==1){
				w+=g;
			}
		}
	}
	for(int i=0;i<d;i++){
		cin>>z>>z1;
		cout<<x[z]+x[z1]+w;
	}
	return 0;
}
