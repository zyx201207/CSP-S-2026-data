#include<bits/stdc++.h>
using namespace std;
bool two(string b,string d){
	for(int i=0;i<=1;i++){
		if(b[i]!=d[i])return 0;
	}
	return 1;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin >> a >> b >> c >> d;
	cout << (a==c);
	bool bo=two(b,d);
	if(a==c){
		cout << bo;
		if(bo){
			if(b[2]<'D'&&d[2]<'D')cout << 1;
			else if(b[2]>='D'&&d[2]>='D')cout << 1;
			else cout << 0;
		}
		else cout << 0;
		if(bo){
			if(b[2]<'D'&&d[2]<'D'){
				if(abs(b[2]-d[2])==1)cout << 1;
				else cout << 0;
			}
			else if(b[2]>='D'&&d[2]>='D'){
				cout << 1;
			}	
			else cout << 0;
		}
		else cout << 0;
	}
	else cout << "000";
	return 0;
}