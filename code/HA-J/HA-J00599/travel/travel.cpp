#include <bits/stdc++.h>
using namespace std;
struct Node{
	int id_c,id_l;
	char id_s;
};
string r1,r2,x1,x2;
Node r,x;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> r1 >> r2 >> x1 >> x2;
	r.id_c=10*(r1[0]-'0')+(r1[1]-'0');
	x.id_c=10*(x1[0]-'0')+(x1[1]-'0');
	r.id_l=10*(r2[0]-'0')+(r2[1]-'0');
	x.id_l=10*(x2[0]-'0')+(x2[1]-'0');
	r.id_s=r2[2];
	x.id_s=x2[2];
	if(r.id_c==x.id_c) cout << 1;
	else{
		cout << "0000";
		return 0;
	}
	if(r.id_l==x.id_l) cout << 1;
	else{
		cout << "000";
		return 0;
	}
	char cr=r.id_s,cx=x.id_s;
	if(cr>cx) swap(cr,cx);
	if(cr<='C'&&cx>='D'){
		cout << "00";
		return 0;
	} 
	else cout << 1;
	if(cx-cr==1||(cx=='F'&&cr=='D')) cout << 1;
	else cout << 0;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
