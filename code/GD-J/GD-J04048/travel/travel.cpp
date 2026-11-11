#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d,ac="0",bc="0",cc="0",dc="0",q,w;
	cin>>a>>b>>c>>d; 
	q=b[2];
	w=d[2];
	if(a==c){
		ac="1";
		if(b[0]==d[0]){
			if(b[1]==d[1]){
				bc="1";
				if(q<="C"&&q>="A"){
					if(w<="C"&&w>="A"){
						cc="1";
						if((q=="A"&&w=="B")||(q=="B"&&w=="C")||(w=="A"&&q=="B")||(w=="B"&&q=="C"))dc="1";
					}
				}
				else if(q=="D"&&w=="F"){
					cc="1";
					dc="1";
				}
				else if(q=="F"&&w=="D"){
					cc="1";
					dc="1";
				}
			}
		}
	}
	cout<<ac<<bc<<cc<<dc;
	return 0;
}



