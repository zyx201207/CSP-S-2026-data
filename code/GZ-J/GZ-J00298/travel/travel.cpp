//GZ-J00298 遵义四中 秦近东	 
#include <bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1[1]==c2[1]&&c1[2]==c2[2]) cout<<"1";
    else{
	cout<<"0000";
	return 0;
    }if(s1[0]+s1[1]==s2[0]+s2[1]){
    	cout<<"1";
	}else{
	cout<<"000";
	return 0;
    }int u=-1;
	if(s1[2]<'D'&&s2[2]<'D'){
    	cout<<"1";
    	u=0;
	}else if(s1[2]>='D'&&s2[2]<'D'){
    	cout<<"1";
    	u=1;
	}else{
		cout<<"00";
	return 0;
	}if(u=1&&s1[2]!=s2[2]&&s1[0]==s2[0]&&s1[1]==s2[1]){
		cout<<"1";
	}else if(u=0&&s1[2]!=s2[2]&&s1[0]==s2[0]&&s1[1]==s2[1]){
		if(s1[2]-s2[2]<2&&s1[2]-s2[2]>-2){
			cout<<"1";
		}
		else{
			cout<<"0";
			return 0;
		}
	}else{
		cout<<"0";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

