#include<bits/stdc++.h> 
using namespace std;
string c1,s1,c2,s2,pai1,pai2;
char hao1,hao2;
bool train,pai,ce,lin,hao1left,hao2left;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	pai1=s1[0]+s1[1];
	pai2=s2[0]+s2[1];
	hao1=s1[2];
	hao2=s2[2];
	if(hao1=='A'||hao1=='B'||hao1=='C')
		hao1left=true;
	if(hao2=='A'||hao2=='B'||hao2=='C')
		hao2left=true;
	if(c1==c2){
		train=true;
		if(pai1==pai2){
			pai=true;
			if(hao1left==hao2left){
				ce=true;
				if(hao1left==true)
					{
						if(hao2-hao1==1||hao1-hao2==1)
							lin=true;
						
					}
				else 
				{
					if(hao2left==false&&hao1-hao2==2||hao2left==false&&hao2-hao1==2)
						lin=true;
				}
			}
		}
	}
	cout<<train<<pai<<ce<<lin;
	return 0;
}
