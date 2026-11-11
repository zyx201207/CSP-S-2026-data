#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
string szj="";
int main(){
	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2)
		szj="0000";
	if(c1==c2){
		szj='1';
		bool pd=true;
		for(int i=0;i<2;i++){
			if(s1[i]!=s2[i]){
				pd=false;
			}
		}
		if(pd){
			szj+='1';
			if(s1[2]>='D'&&s2[2]>='D'){
				szj+="11";
			}else if(s1[2]<'D'&&s2[2]<'D'){
				szj+='1';
				if(abs(int(s1[2]-s2[2]))==1){
					szj+='1';
				}
				else{
					szj+='0';
				}
			}else{
				szj+="00";
			}
		}else{
			szj+="000";
		}
	}
	cout << szj<<endl;
	
	return 0;
} 
