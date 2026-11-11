#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,c;string b,d;cin>>a>>b>>c>>d;
	if(a==c){
	cout<<1;
	if(b[0]==d[0] and b[1]==d[1]){
		cout<<1;
		a=b[2]-='A';
		c=d[2]-='A';
		if((a>=0 and a<=2 and c>=0 and c<=2)or(a>=3 and a<=4 and c>=3 and c<=4)){
			cout<<1;
			if(a-c==1 or a-c==-1)cout<<1;
			else cout<<0;
		}
		else cout<<"00";
	}
	else cout<<"000";
}
else cout<<"0000";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
