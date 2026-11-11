#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel5.in","r",stdin);
	freopen("travel5.out","w",stdout);
	string xi,p,c,l;
	cin>>xi>>p>>c>>l;
	if(xi==c){
		cout<<1;
		if(p[0]==l[0] && p[1]==l[1]){
			cout<<1;
			if((p[2]>'C' && l[2]>'C') or (p[2]<'D' && l[2]<'D')){
				cout<<1;
				if(abs(p[2]-l[2])==1){
					cout<<1;
				}
				else{
					cout<<0;
				}
			}
			else{
				cout<<"00";
			}
		}
		else{
			cout<<"000";
		}
	}
	else{
		cout<<"0000";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
