//GZ-J00164 遵义市汇川区第八小学 黄芷菡 
#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	long long m=s1.size();
	int k=0,l=0,h=0,z=0;
	if(c1==c2){
		k=1;
	}else{
		cout << "0000";
		return 0;
	}
	string ch=s1.substr(0,2),sh=s2.substr(0,2);
	if(ch==sh){
		l=1;
	}else{
		cout << "1000";
		return 0;
	}
	char a=s1[m-1],b=s2[m-1];
	if((a=='A' || a=='B' || a=='C') && (b=='A' || b=='B' || b=='C')){
		h=1;
		if( ((a=='A' && b=='B') || (b=='A' && b=='B')) || ((a=='B' && b=='C') || (b=='B' && a=='C'))){
			z=1;
		}
	}else if((a=='D' || a=='F') && (b=='D' || b=='F')){
		h=1;
		z=1;
	}
	cout << k << l <<  h << z;
	return 0;
}
