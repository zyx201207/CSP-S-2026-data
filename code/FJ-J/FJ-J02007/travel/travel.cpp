#include<bits/stdc++.h>
using namespace std;
int c1,s1,c2,s2;
char l1,l2;
string a1,a2;
bool f1,f2;
void f(){
	cin>>c1>>a1>>c2>>a2;
	s1=(a1[0]-48)*10+a1[1]-48;
	s2=(a2[0]-48)*10+a2[1]-48;
	l1=a1[2];
	l2=a2[2];
	if(l1<='C')f1=1;
	else f1=0;
	if(l2<='C')f2=1;
	else f2=0;
	if(c1==c2){
		cout<<"1";
		if(s1==s2){
			cout<<"1";
			if(f1==f2){
				cout<<"1";
				if(l1>l2)swap(l1,l2);
				if(l1=='A'&&l2=='B'||l1=='B'&&l2=='C'||l1=='D'&&l2=='F'){
					cout<<"1\n";
				}else{
					cout<<"0\n";
					return ;
				}
			}else{
				cout<<"00\n";
				return ;
			}
		}else{
			cout<<"000\n";
			return ;
		}
	}else{
		cout<<"0000\n";
		return ;
	}
}
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
//	freopen("travel5.in","r",stdin);
//	freopen("travel.out","w",stdout);
//	int t;
//	cin>>t;
//	while(t--)
	f();
	return 0;
}
