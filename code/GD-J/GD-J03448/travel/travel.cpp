#include<bits/stdc++.h>
using namespace std;
struct people{
	string l;
	string sit;
	string sit_line;
	string sit_role;
};
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	people r,x;
	cin >> r.l >> r.sit >> x.l >> x.sit;
	if(r.l==x.l){
		cout << 1;
	}
	else{
		cout << 0;
	}
	r.sit_line=r.sit.substr(0,2);
	x.sit_line=x.sit.substr(0,2);
	r.sit_role=r.sit.substr(2,1);
	x.sit_role=x.sit.substr(2,1);
//	cout << endl << r.sit_line << " " << r.sit_role << " " << x.sit_line << " " << x.sit_role; test the cut by sudstr()
	if(r.sit_line==x.sit_line){
		cout << 1;
	}
	else{
		cout << 0;
	}
	if(r.sit_role<"D" && x.sit_role<"D"){
		cout << 1 << " ";
		if(r.sit_role=="A" && x.sit_role=="B"){
			cout << 1;
		}
		else if(r.sit_role=="B" && x.sit_role=="C"){
			cout << 1;
		}
		else if(r.sit_role=="B" && x.sit_role=="A"){
			cout << 1;
		}
		else if(r.sit_role=="C" && x.sit_role=="B"){
			cout << 1;
		}
		else{
			cout << 0;
		}
	}
	else if(r.sit_role>"D" && x.sit_role>"d"){
		cout << 11;
	}
	else{
		cout << 0 << 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
