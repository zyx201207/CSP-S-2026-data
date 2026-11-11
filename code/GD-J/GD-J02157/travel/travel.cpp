#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<"1";
		int flag=1;
		for(int i=0;i<b.size()-1;i++){
			if(b[i]!=d[i]){
				flag=0;
				break;
			}
		}
		if(flag==1){
			cout<<"1";
			char e=b[b.size()-1];
			char f=d[d.size()-1];
			int ff=1;
			if((e=='A'||e=='B'||e=='C')&&(f=='A'||f=='B'||f=='C')){
				cout<<"1";
			}else if((e=='D'||e=='E')&&(f=='D'||f=='E')){
				cout<<"1";
			}else{
				cout<<"00";
				ff=0;
			}
			if(ff==1){
				int ans=abs(e-f);
				if(ans==1){
					cout<<"1";
				}else{
					cout<<"0";
				}
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
}
