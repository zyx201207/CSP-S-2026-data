#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string t_1,t_2,d_1,d_2;
	cin >> t_1 >> t_2 >> d_1 >> d_2;
	if(t_1!=d_1){
		cout << "0000";
	} 
	else if(t_2[0]!=d_2[0]||t_2[1]!=d_2[1]){
		cout << "1000";
	}
	else if((t_2[2]=='D'&&d_2[2]=='C')||(t_2[2]=='C'&&d_2[2]=='D')){
		cout << "1100";
	}
	else if(min(t_2[2],d_2[2])+1!=max(t_2[2],d_2[2])){
		if(min(t_2[2],d_2[2])=='D'&&max(t_2[2],d_2[2])=='F') cout << "1111";
		else cout << "1110";
	}
	else{
		cout << "1111";
	}
	
	return 0;
}
