#include <bits/stdc++.h> 
using namespace std;

const int MAXN = 1e5 + 10;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string a,b,c,d,m,n;
	cin>>a>>b>>m>>c>>d>>n;
	if(a==c)
		cout<<"1";
	else
		cout<<"0";
	if(a==c){
		if(b==d)
			cout<<"1";
		else
			cout<<"0";
	}
	if(a==c){
		if((m=="A"&&n=="B")||(m=="A"&&n=="C")||(m=="B"&&n=="C")||(m=="B"&&n=="A")||(m=="C"&&n=="A")||(m=="C"&&n=="B")||(m=="D"&&n=="F")||(m=="F"&&n=="D"))
			cout<<"1";
		else
			cout<<"0";
	}
	if(a==c){
		if((m=="A"&&n=="B")||(m=="B"&&n=="C")||(m=="C"&&n=="B")||(m=="D"&&n=="F")||(m=="F"&&n=="D"))
			cout<<"1";
		else
			cout<<"0";
	}
	return 0;
}
