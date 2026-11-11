#include<bits/stdc++.h>
using namespace std;
bool place(char a){
	return a=='A' or a=='B' or a=='C';
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	bool b1=0,b2=0,b3=0,b4=0;
	if(c1==c2){
		b1=1;
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			b2=1;
			if(place(s1[2])==place(s2[2])){
				b3=1;
				if(place(s1[2])==0) b4=1;
				else{
					int a=s1[2],b=s2[2];
					if(b>a) swap(a,b);
					if(!(a=='C'&&b=='A')) b4=1;
				}
			}
		}
	}
	cout<<b1<<b2<<b3<<b4;
	return 0;
}
