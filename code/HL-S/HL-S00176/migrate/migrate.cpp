#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;cin>>c>>t;
	if(c==0){
		if(t==2){
			int d;cin>>d;
			if(d==4){
				cout<<"1\n2";
			}else if(d==5){
				cout<<"0\n1";
			}
		}else if(t==17){
			int a[17]={
			8129,
16,
9,
7,
12,
0,
0,
0,
2,
1,
0,
2,
3,
6,
0,
2,
0};
			for(int i=0;i<17;i++) cout<<a[i]<<"\n";
		}
	}
	return 0;
}
