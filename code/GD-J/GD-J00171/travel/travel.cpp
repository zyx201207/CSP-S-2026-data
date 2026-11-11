#include <bits/stdc++.h>
using namespace std;
struct cp{
	string cx;
	int p;
	int z;
};
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cp a,b;
	string ab;
	cin >> a.cx;
	cin >> ab;
	a.p = (int(ab[0])-47) * 10 + int(ab[1] -47);
	a.z = int(ab[2]);
	
	cin >> b.cx;
	cin >> ab;
	b.p = (int(ab[0])-47) * 10 + int(ab[1] -47);
	b.z = int(ab[2]);
	
	if(a.cx == b.cx){
		cout<< "1";
		if(a.p == b.p){
			cout << "1";
			if(a.z <=67 and b.z <=67 or a.z >68 and b.z>68){
				cout <<"1";
				if(a.z + 1 == b.z or a.z-1 == b.z){
					cout <<"1";
				}
				else{
					cout<<"0";
				}
			}
			else{
				cout<<"00";
			}
		}
		else{
			cout<<"000";
		}
	}
	else{
		cout<<"0000";
	}
	fclose(stdin);
	fclose(stdout);
}
