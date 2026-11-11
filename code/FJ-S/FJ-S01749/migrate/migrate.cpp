#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int a,b,c,d,e[100000];
	cin>>a>>b;
	cin>>c>>d;
	for(int j=0;j<b;j++){
		for(int i=0;i<c;i++){
			cin>>e[i];
		}
		if(e[0]-e[1]==e[1]-e[2]){
			cout<<c-3<<endl;
		}
		else{
			cout<<0;
		}
	}
	return 0;
}
