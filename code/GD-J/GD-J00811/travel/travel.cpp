#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define ull unsigned long long 
#define endl '\n' 
string s,t,o,p;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
	
	cin >> s >> t >> o >> p;
	if(s!=o){
		cout << "0000";
		exit(0);
	}else{
		cout << 1;
		if(t[0]==p[0] && t[1]==p[1]){
			cout << 1;
			if((p[2]<='C' && t[2]<='C') || (p[2]>='D' && t[2]>='D')){
				cout << 1;
				if(t[2]+1==p[2] || t[2]-1==p[2]){
					cout << 1;
					exit(0);
				}
				cout << 0;
			}else{
				cout << "00";
				exit(0);
			}
		}else{
			cout << "000";
			exit(0);
		}
	}
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
