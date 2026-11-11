#include<iostream>
#include<string>
#include<cmath>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);  
	cin>>c1>>s1>>c2>>s2;
	char sone=s1[2],stwo=s2[2];
	if(c1==c2){
		cout<<1;
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<<1;
			if((sone>='A'&&sone<='C'&&stwo>='A'&&stwo<='C')||(sone>='D'&&sone<='F'&&stwo>='D'&&stwo<='F')){
				cout<<1;
				if((sone>='A'&&sone<='C'&&stwo>='A'&&stwo<='C'&&abs(int(sone)-int(stwo))==1)||(sone>='D'&&sone<='F'&&stwo>='D'&&stwo<='F')){
					cout<<1;
				}else{
					cout<<0;
				}
			}else{
				cout<<0<<0;
			}
		}else{
			cout<<0<<0<<0;
		}
	}else{
		cout<<0<<0<<0<<0;
	}
	return 0;
}
