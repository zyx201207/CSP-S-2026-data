#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2,t1,t2;
int a,b,c,d;
int abs(int a){
	if(a<0) a=-a;
	return a;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2) {
		cout<<"0000";
		return 0;
	}
	else{
		cout<<"1";
		for(int i=0;i<s1.size()-1;i++){
			t1+=s1[i];
			t2+=s2[i];
		}
		if(t1!=t2){
			cout<<"000";
			return 0;
		}
		else{
			cout<<"1";
			char t3=s1[2],t4=s2[2];
			if(t3=='A' || t3=='B' || t3=='C')a=1;
			else a=2;
			if(t4=='A' || t4=='B' || t4=='C')b=1;
			else b=2;
			if(a!=b){
				cout<<"00";
				return 0;
			}
			else{
				cout<<"1";
				if(a==1){
					if(t3=='A') c=1;
					if(t3=='B') c=2;
					if(t3=='C') c=3;
					if(t4=='A') d=1;
					if(t4=='B') d=2;
					if(t4=='C') d=3;
					if(abs(c-d)==1){
						cout<<"1";
						return 0;
					}else{
						cout<<"0";
						return 0;
					}
				}else{
					cout<<"1";
					return 0;
				}
			}
		}
	}
	return 0;
}
