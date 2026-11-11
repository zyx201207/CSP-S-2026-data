#include <bits/stdc++.h>
using namespace std;
int c1,c2;
int x1,x2;//第几排
int m1,m2;
string s1,s2;
bool f1,f2,f3,f4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	x1=(s1[0]-'0')*10+s1[1]-'0';
	x2=(s2[0]-'0')*10+s2[1]-'0';
	m1=s1[2]-'A'+1;
	m2=s2[2]-'A'+1;
	if(c1==c2){
		f1=1;
		if(x1==x2){
			f2=1;
			if(!(m1<=3 && m2>=4) || (m1>=4 && m2<=3)){
				f3=1;
				if((m1<=3 && abs(m1-m2)==1) || ((abs(m1-m2)==2) && m1>=4)){
					f4=1;
				}else{
					f4=0;
				}
			}else{
				f3=0;
				f4=0;
			}
		}else{
			f2=0;
			f3=0;
			f4=0;
		}
	}else{
		f1=0;
		f2=0;
		f3=0;
		f4=0;
	}
	cout<<f1<<" "<<f2<<" "<<f3<<" "<<f4<<endl;
	
	return 0;
}
