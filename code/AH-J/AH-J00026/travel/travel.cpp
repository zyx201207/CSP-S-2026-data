#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	bool f1=0,f2=0,f3=0,f4=0;
	if(c1==c2){
		f1=1;
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			f2=1;
			ll d1=ll(s1[2]-'A'+1),d2=ll(s2[2]-'A'+1);
			if(d1>=1&&d1<=3&&d2>=1&&d2<=3||d1>=4&&d1<=6&&d2>=4&&d2<=6){
				f3=1;
				if(d1!=3||d2!=4){
					if(d1==4&&d2==6||d1==6&&d2==4) f4=1;
					else if(abs(d1-d2)<=1) f4=1;
				}	
			}	
			
		}
	}	 
	cout<<f1<<f2<<f3<<f4;
	return 0;
} 
