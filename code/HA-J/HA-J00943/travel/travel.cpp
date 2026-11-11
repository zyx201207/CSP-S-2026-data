#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2,w1,w2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) cout<<1;
	else{
		cout<<0<<0<<0<<0;
		return 0;
	}
	w1+=s1[0];
	w1+=s1[1];
	w2+=s2[0];
	w2+=s2[1];
	if(w1==w2) cout<<1;
	else{
		cout<<0<<0<<0;
		return 0;
	}
	w1=s1[2];
	w2=s2[2];
	if(w2<w1) swap(w1,w2);
	if((w1=="A"&&w2=="B")||(w1=="A"&&w2=="C")||(w1=="B"&&w2=="C")||(w1=="D"&&w2=="F")) cout<<1;
	else{
		cout<<0<<0;
		return 0;
	}
	if((w1=="A"&&w2=="B")||(w1=="B"&&w2=="C")||(w1=="D"&&w2=="F")) cout<<1;
	else cout<<0;
	return 0;
}
