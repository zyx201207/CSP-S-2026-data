#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","w",stdin);
	freopen("travel.out","r",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		string a1,a2;
		for(int i=0;i<2;i++){
			a1+=s1[i];
			a2+=s2[i];
		}
		if(a1==a2){
			cout<<1;
			char b1=s1[2],b2=s2[2];
			if('D'<=b1 && 'E'>=b1 && 'D'<=b2 && 'E'>=b2){
				cout<<11;
			}
			else{
				if('A'<=b1 && 'C'>=b1 && 'A'<=b2 && 'C'>=b2){
					cout<<1;
					if(b1+1==b2 || b1-1==b2){
						cout<<1;
					}
					else{
						cout<<0;
					}
				}
			}
		}
		else{
			cout<<000;
		}
	}
	else{
		cout<<0000;
	}

	return 0;
} 
