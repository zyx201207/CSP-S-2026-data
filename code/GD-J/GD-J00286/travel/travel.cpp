#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	string cx,cz,xx,xz;
	cin>>cx>>cz>>xx>>xz;
	if(cx==xx){
		cout<<'1';
		if(cz[0]==xz[0] && cz[1]==xz[1]){
			cout<<'1';
			string a,b;
			if(cz[2]=='A' || cz[2]=='B' || cz[2]=='C'){
				a='z';
			}else{
				a='y';
			}
			if(xz[2]=='A' || xz[2]=='B' || xz[2]=='C'){
				b='z';
			}else{
				b='y';
			}
			if(a==b){
				cout<<'1';
				if(a[0]='z'){
					if(cz[2]+1==xz[2] || cz[2]-1==xz[2]){
						cout<<'1';
					}else{
						cout<<'0';
					}
				}else{
					cout<<'1';
				}
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	} else{
		cout<<"0000";
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
