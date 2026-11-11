#include<bits/stdc++.h>
using namespace std;
typedef long long ll; 
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	char cr,cx;
	ll r1,r2,x1,x2;
	cin >>r1>>r2>>cr>>x1>>x2>>cx;
	
	if (r1 == x1){
		cout <<1;
	}
	else{
		cout <<0;
	}
	if(r1 == x1 && r2 == x2){
		cout <<1;
	}
	else{
		cout <<0;
	}
	if (r1 == x1 && r2 == x2){
		if (cx >= 'A' && cx <= 'C'){
			if (cr >= 'A' && cr <= 'C'){
				cout <<1;
			}
			else{
				cout <<0;
			}
		}
		else if(cx >= 'D' && cx <= 'F'){
			if (cr >= 'D' && cr <= 'F'){
				cout <<1;
			}
			else{
				cout <<0;
			}
		}
		else{
			cout <<0;
		}
	}
	else{
		cout <<0;
	}
	if (r1 == x1 && r2 == x2){
		if (cx >= 'A' && cx <= 'C'){
			if (cr >= 'A' && cr <= 'C'){
				if ( (cr == 'A' && cx == 'B' )|| (cr == 'B' && cx == 'C')){
					cout <<1;
				}
				else{
					cout <<0;
				}
			}
			else{
				cout <<0;
			}
		}
		else if(cx >= 'D' && cx <= 'F'){
			if (cr >= 'D' && cr <= 'F'){
				cout <<1;
			}
			else{
				cout <<0;
			}
		}
		else{
			cout <<0;
		}
	}
	else{
		cout <<0;
	}
	return 0;
}
