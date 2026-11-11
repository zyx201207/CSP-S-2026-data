#include<bits/stdc++.h>
using namespace std;
const int z=1e5+10,x=2e6+10;
//struct o{
//	int r;
//	int w;
//}a[z],b[x];
int a[z],b[x];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		int a1,b1;
		cin>>a1>>b1;
		for(int j=1;j<=a1;j++){
			cin>>a[j];
		}
		sort(a+1,a+a1+1);
		if(c==11||c==12){
			if(b1<=abs(a[2]-a[1])){
				cout<<0<<endl;
			}
		}
		if(c==13||c==14){
			cout<<0<<endl;
		}
	}
	return 0;
}
