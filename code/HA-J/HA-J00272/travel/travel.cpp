#include<iostream>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,s1,c2,s2,m;
	m=0;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		m+=1000;
		if(s1-1==s2||s2-1==s1){
			m+=100;
		}
		else(){
			m+=0;
		}
	}
	else(){
		cout<<"0000";
	}
	
	cout<<m;
	fclose(stdin);
	fclose(stdout);
return 0;
};

