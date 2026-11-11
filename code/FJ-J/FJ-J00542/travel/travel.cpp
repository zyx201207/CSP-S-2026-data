#include<bits/stdc++.h>
using namespace std;
char dx[5]={'A','B','C','D','E'};
int x1,x2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	bool ok1=true;
	for(int i=0;i<2;i++){
		if(c1[i]!=c2[i]){
			ok1=false;
		}
	}
	bool ok2=false;
	if(ok1){
		
		int k=0;
		for(int i=0;i<2;i++){
			if(s1[i]==s2[i]){
				k++;
			}
		}
		if(k==2){
			ok2=true;
		}
	}
	
	bool ok3=false;
	bool ok4=false;
	
	for(int i=0;i<5;i++){
		if(s1[2]==dx[i]){
			x1=i;
		}
		if(s2[2]==dx[i]){
			x2=i;
		}
	}
	if(ok2){
		if((x1<=2 && x2<=2) || (x1>=3 && x2>=3)){
		ok3=true;
	}
	}
	if(ok3){
		int tnt=abs(x1-x2);
		if(tnt==1){
			ok4=true;
		}
	} 
	if(ok1){
		cout<<1;
	}
	else{
		cout<<0;
	}
	if(ok2){
		cout<<1;
	}
	else{
		cout<<0;
	}
	if(ok3){
		cout<<1;
	}
	else{
		cout<<0;
	}
	if(ok4){
		cout<<1;
	}
	else{
		cout<<0;
	}
	return 0;
}
