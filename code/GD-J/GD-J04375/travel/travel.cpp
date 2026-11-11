
#include<bits/stdc++.h>
using namespace std;
string c2,c4;
char s1,s2;
int c1,c3;
int m=2,x,y;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >>c1>>c2>>c3>>c4;
	/*
	cout <<c1<<" "<<c3<<endl;
	cout <<c2<<" "<<c4;
	*/
	for(int i=0;i<m;i++){
		x=x*10+(int)c2[i]-'0';
		y=y*10+(int)c4[i]-'0';
	}
	s1=c2[m],s2=c4[m];
	if(c1!=c3){
		cout <<"0000";
	}else{
		cout <<1;
		if(x!=y){
			cout <<"000";
		}else{
			cout <<1;
			if(s1<'D'&&s2<'D'){
				cout <<1;
				if(s1+1==s2)cout <<1;
				else cout <<0;
			}else if(s1>='D'&&s2>='D')cout <<11;
			else cout <<"00";
		}
	}
	return 0;
} 

