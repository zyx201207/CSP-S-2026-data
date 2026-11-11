//GZ-J00182 北京师范大学贵阳附属中学 赵瀚成 
#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2,x,y;
int s=0;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in","r","stdin");
	freopen("travel.out","w","stdout");
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		for(int i=0;i<3;i++){
			if(i==2){
				x=s1[i];
				y=s2[i];
			}
			if(s1[i]!=s2[i]&&i!=2){
				cout<<"000";
				return 0;
			}
		}
		cout<<1;
		if(((x=="A"||x=="B"||x=="C")&&(y=="A"||y=="B"||y=="C"))||((x=="D"||x=="F")&&(y=="D"||y=="F"))){
			cout<<1;
			if((x=="A"&&y=="B")||(x=="B"&&y=="A")||(x=="C"&&y=="B")||(x=="B"&&y=="C")||(x=="D"&&y=="F")||(x=="F"&&y=="D")){
				cout<<1;
				return 0;
			}
			else{
				cout<<0;
				return 0;
			}
		}
		else{
			cout<<"00";
			return 0;
		}
	}
	else{
		cout<<"0000";
		return 0;
	}
	return 0;
}
