//øº∫≈£∫GZ-J00329
//–’√˚£∫÷£»Ÿ»Ò 
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);

	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	for(int i=0;i<c1.size();i++){ 
		if(c1[i]!=c2[i]){
			cout<<"0000";
			fclose(stdin);
	        fclose(stdout);
			return 0;
		}
		if(i==c1.size()-1){
			cout<<"1";
		}
	}
	
	for(int i=0;i<s1.size()-1;i++){
		if(s1[i]!=s2[i]){
			cout<<"000";
			fclose(stdin);
	        fclose(stdout);
			return 0;
		}
		if(i==s1.size()-2){
			cout<<"1";
		}
	}
	
	if((s1[2]>='A'&&s1[2]<='C')&&(s2[2]>='A'&&s2[2]<='C')){ 
		cout<<"1";
	}else if((s1[2]>='D'&&s1[2]<='F')&&(s2[2]>='D'&&s2[2]<='F')){
		cout<<"1";
	}else{
		cout<<"00";
		fclose(stdin);
	    fclose(stdout);
		return 0;
		
	}
	
	if((s1[2]-'0'+1==s2[2]-'0')||(s2[2]-'0'+1==s1[2]-'0')) {
		cout<<"1";
	}else{
		cout<<"0";
	}
	
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
