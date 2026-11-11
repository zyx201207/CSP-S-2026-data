#include<bits/stdc++.h>//8:51finish样例全过 
using namespace std;
int c1,c2;
string s1,s2;
int a1,a2;
char ch1,ch2;
int main(){//关注dlc666嘛，b站叫大破车dlc666 
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout); 
	cin>>c1>>s1>>c2>>s2;
	for(int i=0;i<2;++i){
		a1=a1*10+s1[i]-'0';
		a2=a2*10+s2[i]-'0';
	}
	ch1=s1[2],ch2=s2[2];
	if(ch1-'A'>ch2-'A'){
		swap(ch1,ch2);
	}
//	cout<<ch1<<' '<<ch2<<endl;
	if(c1==c2){
		cout<<'1';
		if(a1==a2){
			cout<<'1';
			if((ch1>='A'&&ch1<='C')&&(ch2>='A'&&ch2<='C')){
				cout<<'1';
				if((ch1=='A'&&ch2=='B')||(ch1=='B'&&ch2=='C')){
					cout<<'1';
				}else{
					cout<<'0';
				}
			}else if(ch1=='D'&&ch2=='F'){
				cout<<"11";
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
} 
