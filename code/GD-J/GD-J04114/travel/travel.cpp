#include<bits/stdc++.h>
using namespace std;
struct p{
	string c,z,h;
	int bh;
};
p a[3];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	for(int i=1;i<=2;i++){
		cin>>a[i].c>>a[i].z;
		a[i].h=a[i].z[0]+a[i].z[1];
		a[i].bh=(a[i].h[0]-'0')*10+(a[i].h[1]-'0');
		a[i].z=a[i].z[2];
}
	
	if(a[1].c==a[2].c){
		cout<<1;
		if(a[1].bh==a[2].bh){
			cout<<1;
			int x=int(a[1].z[0]-'A');
			int y=int(a[2].z[0]-'A');
			if(x<=2 && y<=2 || x>2 && y>2){
				cout<<1;
				if(abs(x-y)==1) cout<<1;
				else cout<<0;
			}else cout<<"00";
				
				
		}else cout<<"000";
	}else cout<<"0000";
	return 0;
}
