#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	string r,x;
	cin>>c1>>r>>c2>>x;
	if(x == r){
		cout<<"0000";
		return 0;
	}
	if(c1 == c2){
		cout<<1;
		char r1 = r[0],r2 = r[1],x1 = x[0],x2 = x[1];
		if(r1 == x1 && r2 == x2){
			cout<<1;
			if(((r[2] == 'A' or r[2] == 'B' or r[2] == 'C') and (x[2] == 'A' or x[2] == 'B' or x[2] == 'C')) or ((r[2] == 'E' or r[2] == 'F') and (x[2] == 'E' or x[2] == 'F'))){
				cout<<1;
				if((r[2] == (char)(x[2] + 1) or r[2] == (char)(x[2] - 1)) or (r[2] == (char)(x[2] + 1) or r[2] == (char)(x[2] - 1)))cout<<1;
				else{
					cout<<"0";
					return 0;
				}
			}else{
				cout<<"00";
				return 0;
			}
		}else{
			cout<<"000";
			return 0;
		}
	}else cout<<"0000";
	fclose(stdin);
	fclose(stdin);
	return 0;
}
