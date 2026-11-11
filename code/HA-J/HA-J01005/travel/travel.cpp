#include<bits/stdc++.h>
using namespace std;
int c1,c2,sa,sb,w1,w2;
string s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	w1=s1[2]-'A'+1;
	w2=s2[2]-'A'+1;
	if(s1[2]=='F'){
		w1--;
	}if(s2[2]=='F'){
		w2--;
	}
	if(c1!=c2){
		cout<<0<<0<<0<<0;
		return 0;
	}
	else{
		cout<<1;
		sa=(s1[0]-'0')*10+(s1[1]-'0');
		sb=(s2[0]-'0')*10+(s2[1]-'0');
		if(sa!=sb){
			cout<<0<<0<<0;
			return 0;
		}
		else{
			cout<<1;
			if((w1<=3&&w2<=3)||(w1>3&&w2>3)){
				cout<<1;
					if(w1-w2==1||w2-w1==1){
						cout<<1;
					}else{
						cout<<0;
					}
			}
			else{
				cout<<0<<0;
				return 0;
			}
		}
	}
	return 0;
}
