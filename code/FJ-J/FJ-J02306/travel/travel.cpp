#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int n,m,b=0;
	string a,s;
	cin >>n >>a >>m >>s;
	if(n==m){
		cout <<1;
		if(a[0]==s[0] && a[1]==s[1]){
			cout <<1;
			if(a[2]=='C' && s[2]=='D' || a[2]=='D' && s[2]=='C'){
				cout <<"00";
			}else{
				if(a[2]=='A'){
					if(s[2]=='B' ||s[2]=='C'){
						cout <<1;
					}else{
						cout <<0;
					}
				}else if(a[2]=='B'){
					if(s[2]=='A' ||s[2]=='C'){
						cout <<1;
					}else{
						cout <<0;
					}
				}else if(a[2]=='C'){
					if(s[2]=='A' ||s[2]=='B'){
						cout <<1;
					}else{
						cout <<0;
					}
				}else if(a[2]=='D'){
					if(s[2]=='E'){
						cout <<1;
					}else{
						cout <<0;
					}
				}else if(a[2]=='E'){
					if(s[2]=='D'){
						cout <<1;
					}else{
						cout <<0;
					}
				}
				if(a[2]==s[2]+1 || a[2]==s[2]-1){
					cout <<1;
					b=1;
				}else{
					cout <<0;
				}
			}
		}else{
			cout <<"000";
		}
	}else{
		cout <<"0000";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
