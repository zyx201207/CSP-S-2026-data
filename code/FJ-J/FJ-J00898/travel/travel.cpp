#include<bits/stdc++.h>
using namespace std;
string a,a_,b,b_;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>a_>>b>>b_;
	if(a[0]==b[0]&&a[1]==b[1]){
		if(a_[0]==b_[0]&&a_[1]==b_[1]){
			if((a_[2]<='C'&&b_[2]<='C')||(a_[2]>='D'&&b_[2]<='D')){
				if((a_[2]=='A'&&b_[2]=='B')||(a_[2]=='B'&&(b_[2]=='A'||b_[2]=='C'))||(a_[2]=='C'&&b_[2]=='B')||(a_[2]=='D'&&b_[2]=='F')||(a_[2]=='F'&&b_[2]=='D')){ 
					cout<<"1111"; 
				}
				else cout<<"1110";
			}
			else cout<<"1100";
		}
		else cout<<"1000";
	}
	else cout<<"0000";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
