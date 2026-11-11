#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,c;
	string d,b;
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<1;
	}else{
		cout<<0;
	}
	for(int i=0;i<=3;i++){
		if(d[0]==b[0]&&d[1]==b[1]){
			cout<<1;
		}else{
			cout<<0;
		}
		if(d[2]==b[2]){
			cout<<0;
		}else if(d[2]-b[2]==1){
			cout<<1;
		}else{
			cout<<0;
		}
	}
	return 0;
}
