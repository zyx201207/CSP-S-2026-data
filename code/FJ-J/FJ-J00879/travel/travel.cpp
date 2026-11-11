#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c){
		if(b[0]==d[0] and b[1]==d[1]){
			long long ca=b[2]-'A',cb=d[2]-'A';
			if((ca<=2 and cb<=2) or (ca>2 and cb>2)){
				if(abs(ca-cb)==1){
					cout<<"1111\n";
				}else{
					cout<<"1110\n";
				}
			}else{
				cout<<"1100\n";
				return 0;
			}
		}else{
			cout<<"1000\n";
			return 0;
		}
	}else{
		cout<<"0000\n";
		return 0;
	}
	return 0;
} 
