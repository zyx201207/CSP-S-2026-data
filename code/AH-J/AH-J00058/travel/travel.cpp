#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<1;
		if(b.substr(0,b.size()-1)==d.substr(0,d.size()-1)){
			cout<<1;
			char m=b[b.size()-1];
			char n=d[d.size()-1];
			char x=max(m,n);
			char y=min(m,n);
			if(x=='D'&&y=='C'){
				cout<<"00";
				return 0;
			}else{
				cout<<1;
				if((x-y==1&&x!='D')||(x=='F'&&y=='D')){
					cout<<1;
					return 0;
				}else{
					cout<<0;
					return 0;
				}
			}
		}else{
			cout<<"000";
			return 0;
		}
	}else{
		cout<<"0000";
		return 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
