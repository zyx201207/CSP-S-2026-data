#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	int x1=(c1[0]-'0')*10+(c1[1]-'0');
	int x2=(c2[0]-'0')*10+(c2[1]-'0');
	if(x1==x2){
		int p1=(s1[0]-'0')*10+(s1[1]-'0');
		int p2=(s2[0]-'0')*10+(s2[1]-'0');
		if(p1==p2){
			int z1=(s1[2]-'A'),f1=0;
			int z2=(s2[2]-'A'),f2=0;
			for(int i=0;i<=2;i++){
				if(z1==i)f1=1;
				if(z2==i)f2=1;
			}
			if(f1==f2){
				if(z1==z2+1||z2==z1+1){
					cout<<"1111";
				}
				else cout<<"1110";
			}
			else cout<<"1100";
		}
		else cout<<"1000";
	}
	else cout<<"0000";
	return 0;
} 
