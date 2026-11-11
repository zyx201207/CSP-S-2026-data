#include<iostream>
using namespace std;
string s1,c1,s2,c2,p1,p2;
bool pd(int x,int y){
	if((x<3&&y<3)||(x>2&&y>2)){
		return true;
	}else return false;
}
int main(){
	string s1,c1,s2,c2;
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>c1>>s2>>c2;
	p1+=c1[0]+c1[1],p2+=c2[0]+c2[1];
	int z1=c1[2]-'A',z2=c2[2]-'A';
	if(s1==s2){
		cout<<"1";
		if(p1==p2){
			cout<<"1";
			if(pd(z1,z2)){
				cout<<"1";
				if(max(z1,z2)-min(z1,z2)==1){
					cout<<"1";
				}else{
					cout<<"0";
				}
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
} 
