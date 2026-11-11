#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,s1,s2;
	int a1,a2,a3,a4,l1,l2;
	cin>>c1>>l1>>s1>>c2>>l2>>s2;
	if(c1==c2){
		a1=1;
		cout<<a1;
		if(l1==l2){
			a2=1;
			cout<<a2;
			if(a2==a1){
				if((s1=="A"&s2=="B")||(s1=="B"&s2=="A")){
					a3=1;
					a4=1;
					cout<<a3<<a4;
				}
				else if((s1=="C"&s2=="B")||(s1=="B"&s2=="C")){
					a3=1;
					a4=1;
					cout<<a3<<a4;
				}
				else if((s1=="D"&s2=="C")||(s1=="C"&s2=="D")){
					a3=0;
					a4=0;
					cout<<a3<<a4;
				}
				else if((s1=="D"&s2=="F")||(s1=="F"&s2=="D")){
					a3=1;
					a4=1;
					cout<<a3<<a4;
				}
			}
		}
		else{
			a2=0;
			a3=0;
			a4=0;
			cout<<a2<<a3<<a4;
		}
	}
	else{
		a1=0;
		a2=0;
		a3=0;
		a4=0;
		cout<<a1<<a2<<a3<<a4;
	}
	
	return 0;
}
