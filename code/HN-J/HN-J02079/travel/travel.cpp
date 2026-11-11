#include<bits/stdc++.h>
using namespace std;
string r1,r2,x1,x2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>r1>>r2>>x1>>x2;
	if(r1!=x1){
		cout<<"0000";
		return 0;
	}
	cout<<1;
	if(!(r2[0]==x2[0]&&r2[1]==x2[1])){
		cout<<"000";
		return 0;
	}
	cout<<1;
	if(r2[2]=='F'||r2[2]=='D'){
		if(x2[2]=='F'||x2[2]=='D'){
			cout<<1;
		}
		else{
			cout<<"00";
			return 0;
		}
	}
	else{
		if(x2[2]!='F'&&x2[2]!='D'){
			cout<<1;
		}
		else{
			cout<<"00";
			return 0;
		}
	}
	if(r2[2]==x2[2]+1||r2[2]==x2[2]-1){
		cout<<1;
	}
	else{
		cout<<0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
