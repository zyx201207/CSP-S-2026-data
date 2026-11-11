#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
		char a1=s1[0],a2=s1[1],a3=s2[0],a4=s2[1];
		string r1="";
		r1+=a1;
		r1+=a2;
		string r2="";
		r2+=a3;
		r2+=a4;
		if(r1==r2){
			cout<<"1";
			char t1=s1[2];
			char t2=s2[2];
			string w1="";
			string w2="";
			w1+=t1;
			w2+=t2;
			if(((w1=="A")&&(w2=="B")) || ((w1=="A")&&(w2=="C")) || ((w1=="B")&&(w2=="A")) || ((w1=="B")&&(w2=="C")) || ((w1=="C")&&(w2=="A")) || ((w1=="C")&&(w2=="B")) || ((w1=="C")&&(w2=="A")) || ((w1=="D")&&(w2=="F")) || ((w1=="F")&&(w2=="D"))){
				cout<<"1";
				if(((w1=="A")&&(w2=="B")) || ((w1=="B")&&(w2=="A")) ||  ((w1=="B")&&(w2=="C")) || ((w1=="C")&&(w2=="B")) || ((w1=="D")&&(w2=="F")) || ((w1=="F")&&(w2=="D"))){
					cout<<"1";
				}else{
					cout<<"0";
				}
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
