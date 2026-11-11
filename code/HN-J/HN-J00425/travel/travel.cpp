#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int r,x,r2,x2;
	string r1,x1;
	cin>>r>>r1>>x>>x1;
	if(r!=x){
		cout<<"0000";
	}else{
		cout<<"1";
		if(r1[0]==x1[0]&&r1[1]==x1[1]){
			cout<<"1";
			if((r1[2]>='A'&&r1[2]<='C'&&x1[2]>='A'&&x1[2]<='C')||(r1[2]>='D'&&r1[2]<='F'&&x1[2]>='D'&&x1[2]<='F')){
				cout<<"1";
			}else{
				cout<<"0";
			}
		}else{
			cout<<"00";
		}
		r2=(r1[0]-'0')*10+(r1[1]-'0');
		x2=(x1[0]-'0')*10+(x1[1]-'0');
		if(r1[2]==x1[2]){
			if(r2+1==x2||r2-1==x2){
				cout<<"1";
			}else{
				cout<<"0";
			}
		}else if(r2==x2){
			if((r1[2]>='A'&&r1[2]<='C'&&x1[2]>='A'&&x1[2]<='C'&&(r1[2]==x1[2]+1||r1[2]==x1[2]-1))||(r1[2]>='D'&&r1[2]<='F'&&x1[2]>='D'&&x1[2]<='F'&&(r1[2]==x1[2]+1||r1[2]==x1[2]-1))){
				cout<<"1";
			}else{
				cout<<"0";
			}
		}else{
			cout<<"0";
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
