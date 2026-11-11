#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+10;
string c1,c2,s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		string t1={s1[0],s1[1]},t2={s2[0],s2[1]};
//		cout<<"\n"<<t1<<" "<<t2<<"\n";
		if(t1==t2){
			cout<<1;
			char t3=s1[2],t4=s2[2];
			if((t3<='C'&&t4<='C')||(t3>='D'&&t4>='D')){
				cout<<1;
				int x=t3-t4;
				if(abs(x)==1){
					cout<<1;
				}
				else{
					cout<<0;
				}
			}
			else{
					cout<<"00";
				}
		}
		else{
			cout<<"000";
		}
	}
	else{
		cout<<"0000";
	}
//	cout<<"\n"<<c1+1<<" "<<s1+1<<" "<<c2+1<<" "<<s2+1;
	
	return 0;
}
