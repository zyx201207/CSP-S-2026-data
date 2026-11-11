#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
bool f;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){//1
		cout<<1;
		if(s1[0]==s2[0] && s1[1]==s2[1]){//2
			cout<<1;
			int t1=s1[2]-'0',t2=s2[2]-'0';
			if((t1>=17 && t1<=19)&&(t2>=17 && t2<=19)){//3
				cout<<1;
				if(t1==17 && t2==18) f=1;
				if(t1==18 && (t2==17 || t2==19)) f=1;
				if(t1==19 && t2==18) f=1;
				if(f==1) cout<<1;
				else cout<<0;
			}
			else if((t1>=20 && t1<=21)&&(t2>=20 && t2<=21)){
				cout<<1;
				if(t1==20 && t2==21) f=1;
				if(t1==21 && t2==20) f=1;
				if(f==1) cout<<1;
				else cout<<0;
			}else cout<<"00";
		}else cout<<"000";
	}else cout<<"0000";
	
	return 0;
}
