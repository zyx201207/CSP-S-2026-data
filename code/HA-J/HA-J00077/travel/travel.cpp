#include<bits/stdc++.h>
using namespace std;

string ac,bc;
string as,bs;
string s;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin>>ac>>as>>bc>>bs;
	if(ac==bc){
		if(as.substr(0,2)==bs.substr(0,2)){
			if((as[2]<='C'&&bs[2]<='C')||(as[2]>'C'&&bs[2]>'C')){
				if(abs(as[2]-bs[2])==1) cout<<"1111";
				else cout<<"1110";
			}else cout<<"1100";
		}else cout<<"1000";
	}
	else cout<<"0000";
	
	return 0;
}
/*
until 11:04
I have finished all the task 
besides correct by using duipai
I am so bored
11:05
I find I CANCEL the freopen!!!
11:14 
I forget how to calculate the time of the text=(
*/
/*
nu fa chong guan ping lan chu
xiao xiao yu xie
tai wang yan 
yang tian chang xiao
...
bai le shao nian tou
kong bei xie  
...
I wish my situation is nu fa chong guan ,instead of kong bei qie
*/
