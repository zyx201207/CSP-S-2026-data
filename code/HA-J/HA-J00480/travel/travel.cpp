/* 
QAQ
gei ge guan zhu miao~
id:ABANDON_AC
30min qian dao
ept:100pts
*/
#include<bits/stdc++.h>
#define AFO return 0; 
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a1,a2,b1,b2;
	char c1,c2;
	scanf("%d %d%c %d %d%c",&a1,&b1,&c1,&a2,&b2,&c2);
	if(a1==a2){	
		cout<<1;
		if(b1==b2){
			cout<<1;
			if(c1=='A'||c1=='B'||c1=='C'){
				if(c2=='A'||c2=='B'||c2=='C'){
					cout<<1;
					if(c1+1==c2||c1-1==c2)
						cout<<1;
					else
						cout<<0;
				}
				else
					cout<<"00";
			}
			else if(c2=='D'||c2=='E')
			{
				cout<<1;
				if(c1+1==c2||c1-1==c2)
					cout<<1;
				else
					cout<<0;
			}
			else
				cout<<"00";
		}
		else
			cout<<"000";
	}
	else
		cout<<"0000";
	AFO
}
