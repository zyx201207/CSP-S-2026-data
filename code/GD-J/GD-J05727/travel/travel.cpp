#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c1, s1, c2, s2;
	char lie1, lie2;
	string pai1 = "", pai2 = "";
	cin>>c1>>s1>>c2>>s2;
	lie1 = s1[2];
	lie2 = s2[2];
	pai1 += s1[0];
	pai1 += s1[1];
	pai2 += s2[0];
	pai2 += s2[1]; 
	if(c1 == c2){
		cout<<"1";
		if(pai1 == pai2){
			cout<<"1";
			if(((lie1 == 'A' || lie1 == 'B' || lie1 == 'C') && (lie2 == 'A' || lie2 == 'B' || lie2 == 'C')) || ((lie1 == 'D' || lie1 == 'F') && (lie2 == 'D' || lie2 == 'F'))){
				cout<<"1";
				if(lie1+1 == lie2 || lie1-1 == lie2){
					cout<<"1";
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
	return 0;
} 
