//GZ-J00346ª∆≤≈ËÚ 
#include<iostream>
#include<string>
#include<cmath>

using namespace std;

struct C{
	string a;
	string b;
};

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);

	C x,y;
	cin>>x.a>>x.b;
	cin>>y.a>>y.b;

	if(x.a != y.a){
		cout<<"0000";
		return 0;
	}
	else{
		cout<<"1";
		if(x.b[1] != y.b[1]){
			cout<<"000";
			return 0;
		}else{
			cout<<"1";
			bool p = 0;
			if((x.b[2] == 'F' || x.b[2] == 'D' && y.b[2] == 'D' || y.b[2] == 'F')) p = 1;
			else if(x.b[2] == 'A' || x.b[2] == 'B' || x.b[2] == 'C' && y.b[2] == 'A' || y.b[2] == 'B' || y.b[2] == 'C') p = 1;
			if(!p){
				cout<<"00";
				return 0;
			}else{
				cout<<"1";
				if(abs(int(x.b[2]) - int(y.b[2])) == 1){
					cout<<"1";
				}else{
					cout<<"0";
				}
			}
		}
	}
	return 0;
}
