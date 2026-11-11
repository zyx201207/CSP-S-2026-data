#include <bits/stdc++.h>
using namespace std;
string c,s,x,y;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c>>s>>x>>y;
	if(c==x){
		cout<<"1";
		int p=0;
		for(int i=0;i<2;i++){
			if(s[i]!=y[i]){
				p=1;
				break;
			}
		}
		if(p==0){
			cout<<"1";
			if(s[2]>='A'&&s[2]<='C'&&y[2]>='A'&&y[2]<='C'||s[2]>='D'&&s[2]<='F'&&y[2]>='D'&&y[2]<='F'){
				cout<<"1";
				if(s[2]>='A'&&s[2]<='C'&&y[2]>='A'&&y[2]<='C'){
					if(abs(int(s[2])-int(y[2]))==1){
						cout<<"1";
					}else{
						cout<<"0";
					}
				}else if(s[2]<='D'&&s[2]<='F'&&y[2]>='D'&y[2]<='F'){
					if(abs(int(s[2])-int(y[2]))==2){
						cout<<"1";
					}else{
						cout<<"0";
					}
				}else{
					cout<<"0";
				}
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
			return 0;
		}
	}else{
		cout<<"0000";
		return 0;
	}
	return 0;
}
