#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int col1,col2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	int c11,s11,c22,s22;
	if(c1[0]=='0') c11=c1[1]-'0';
	else c11=(c1[0]-'0')*10+c1[1]-'0';
	if(c2[0]=='0') c22=c2[1]-'0';
	else c22=(c2[0]-'0')*10+c2[1]-'0';
	
	if(s1[0]=='0') s11=s1[1]-'0';
	else s11=(s1[0]-'0')*10+s1[1]-'0';
	if(s2[0]=='0') s22=s2[1]-'0';
	else s22=(s2[0]-'0')*10+s2[1]-'0';
	
	col1=s1[2]-'A'+1,col2=s2[2]-'A'+1;
	
//	cout<<c11<<' '<<s11<<' '<<col1<<endl;
//	cout<<c22<<' '<<s22<<' '<<col2<<endl;

	if(c11!=c22) {
		cout<<"0000";
		return 0;
	} 
	else {
		cout<<1;
		if(s11==s22) cout<<1;
		else cout<<0;
		
		if(s11==s22){
			if(col1<=3&&col2<=3) cout<<1;
			else if(col1>=4&&col2>=4) cout<<1;
			else cout<<0;
		} 
		else cout<<0;
		
		if(s11==s22){
			if(col1<=3&&col2<=3) {
				if(abs((int)(col1-col2))==1){
					cout<<1;
				}
				else cout<<0;
			}
			else if(col1>=4&&col2>=4) {
				if(abs((int)(col1-col2))==1){
					cout<<1;
				}
				else cout<<0;
			}
			else {
				cout<<0;
			}
		} 
		else cout<<0;
	}
}










