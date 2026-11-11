#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,s1,c2,s2;
	char l1,l2;
	scanf("%d %d%c %d %d%c",
		  &c1,&s1,&l1,&c2,&s2,&l2);
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}else{
		if(s1!=s2){
			cout<<"1000";
			return 0;
		}else{
			if((l1<='C'&&l2>'C')||
			   (l1>'C'&&l2<='C')){
				cout<<"1100";
				return 0;
			}
			else{
				if((l1=='A'&&l2=='B')||
				   (l1=='B'&&l2=='C')||
				   (l1=='D'&&l2=='F'))
					cout<<"1111";
				else
					cout<<"1110";
				return 0;
			}
		}
	}
}
