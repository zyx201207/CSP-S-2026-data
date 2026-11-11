#include<bits/stdc++.h>
using namespace std;
int main(){
	string c1,s1,c2,s2;
	bool f1=0,f2=0;
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	else{
		cout<<1;
		for(int i=0;i<2;i++){
			if(s1[i]!=s2[i])f1=1;
		}
		if(f1){
			cout<<"000";
			return 0;
		}
		else{
			cout<<1;
			if((s1[2]-int('A'))<3 and (s2[2]-int('A'))<3 or (s1[2]-int('A')>=3) and (s2[2]-int('A'))>=3){
				f2=1;
			}
			if(f2){
				cout<<1;
				int x1=s1[2]-int('A'),x2=s2[2]-int('A');
				if(x1>=3)x1++;
				if(x2>=3)x2++;
				if(abs(x1-x2)==1)cout<<1;
				else cout<<0;
				return 0;
			}
			else{
				cout<<"00";
				return 0;
			}
		}
	}
} 
