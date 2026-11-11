#include<bits/stdc++.h>
using namespace std;
string a1,a2;
int c1,c2;
string ans;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","l",stdout);
	cin>>c1>>a1>>c2>>a2;
	if(c1==c2){
		ans+='1';
		int nub1=(a1[0]-'0')*10+a1[1]-'0',nub2=(a2[0]-'0')*10+a2[1]-'0';
//		cout<<nub1<<" "<<nub2<<" "<<ans;
		if(nub1==nub2){
			ans+='1';
			int w1=a1[2]-'A'+1,w2=a2[2]-'A'+1;
			if(min(w1,w2)<=3 && max(w1,w2)<=3){
				ans+='1';
				if(min(w1,w2)+1==max(w1,w2)){
					ans+='1';
				}
				else{
					ans+='0';
				}
			}
			else if(min(w1,w2)>3){
				ans+='1';
				ans+='1';
			}
			else{
				ans+='0';
				ans+='0';
			}
		}
		else{
			ans+='0';
			ans+='0';
			ans+='0';
		}
	}
	else{
		cout<<"0000";
	}
	cout<<ans;
	return 0;
} 
