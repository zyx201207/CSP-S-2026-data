#include<bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2,d;
int main(){
	//freopen("travel.in","r",stdin);
	//freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		d+='1';
		if(s1[1]==s2[1]&&s2[0]==s1[0]){
			d+='1';
			if(s1[2]=='C'&&s2[2]=='D'||s1[2]=='D'&&s2[2]=='C'){
				d+='0';
				d+='0';
			}else{
				if(s1[2]>'C'&&s2[2]>'C'){
					d+='1';
					if(s1[2]<=s2[2]||s1[2]>s2[2]){
						d+='1';
					}else{
						d+='0';
					}
				}else{
					if(s1[2]<'D'&&s2[2]<'D'){
						d+='1';
						if(s1[2]<=s2[2]||s1[2]>s2[2]){
						d+='1';
					}else{
						d+='0';
					}
					}else{
					d+='0';
					d+='0';
				}
				}
			}
		}else{
			d+='0';
			d+='0';
			d+='0';
		}
}else{
	d+='0';
	d+='0';
	d+='0';
	d+='0';
}
	cout<<d;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
