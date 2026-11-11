#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000"<<'\n';
		return 0;
	}else{
		cout<<1;
		string j,k;
		j=s1[0]+s1[1];
		k=s2[0]+s2[1];
		if(j!=k){
			cout<<"000"<<'\n';
			return 0;
		}else{
			cout<<1;
			char q,e;
			q=s1[2],e=s2[2];
			if(((q!='F'&&q!='D')&&(e!='F'&&e!='D'))||((q!='A'&&q!='B'&&q!='C')&&(e!='A'&&e!='B'&&e!='C'))){
				cout<<1;
				if((q=='F'&&e=='D')||(q=='A'&&e=='B')||(q=='B'&&e=='C')||(q=='D'&&e=='F')||(q=='B'&&e=='A')||(q=='C'&&e=='B')){
					cout<<1<<'\n';
					return 0;
				}else{
					cout<<0<<'\n';
					return 0;
				}
			}else{
				cout<<"00"<<'\n';
				return 0;
			}
		}	
	}
	return 0;
}
