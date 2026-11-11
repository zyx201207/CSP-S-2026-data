//GZ-J00238 中央民族大学附属中学贵阳学校  杨忠瀚 
#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2,ans;
string id1,id2;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);

	cin>>c1>>s1>>c2>>s2;
	
	if(c1==c2){
		ans+='1';	
		id1+=s1[0];
		id1+=s1[1];
		id2+=s2[0];
		id2+=s2[1];
		if(id1==id2){
			ans+='1';
			if(s1[2]+s2[2]!='C'+'D'){
				ans+='1';
				if((s1[2]-s2[2]==1)||(s1[2]-s2[2]==-1)){
					if(s1[2]+s2[2]!='C'+'D')ans+='1';
					else ans+='0';
				}else ans="1110";
			}
			else ans="1100";
		}
		else ans="1000";
	}
	else ans="0000";
	
	cout<<ans;
	return 0;
}
