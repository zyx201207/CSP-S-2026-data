#include<iostream>
#include<cmath>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b;
	string c,d;
	cin>>a>>c>>b>>d;
	if(a == b){
		cout<<1;
		if(c[0] == d[0] && c[1] == d[1]) cout<<1;
		else{
			cout<<"000";
			return 0;
		}
		if((c[2] <= 'C' && d[2] <= 'C') || ((c[2] >= 'D' && c[2] <= 'F') && (d[2] >= 'D' && d[2] <= 'F'))) cout<<1;
		else{
			cout<<"00";
			return 0;
		}
		if((c[1] - d[1] == 0 && abs(c[2] - d[2]) == 1) || abs(c[3] - d[3]) == 1) cout<<1;
		else cout<<"0";
	}
	else{
		cout<<"0000";
		return 0;
	}
	return 0;
} 
