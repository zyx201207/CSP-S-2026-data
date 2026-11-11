#include<bits/stdc++.h>
using namespace std;
string a,b,c,d,e,f;
char g,h;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<1;
		for(int i = 0;i<(int)b.size();i++){
			if(b[i]>='0'&&b[i]<='9')e+=b[i];
			else g=b[i];
		}
		for(int i = 0;i<(int)d.size();i++){
			if(d[i]>='0'&&d[i]<='9')f+=d[i];
			else h=d[i];
		}
		if(e==f){
		    cout<<1;
		    if((g<='C'&&h<='C')||(g>='D'&&h>='D')){
				cout<<1;
				int gg=g-'A';
				int ff=h-'A';
				if((gg==ff+1)||(ff==gg+1)){
					cout<<1;
				}else{
					cout<<0;
				}
		    }else{
				cout<<"00";
		    }
		}else{
			cout<<"000";
		}
	}
	else{
		cout<<"0000";
	}
	
	return 0;
}
