#include<bits/stdc++.h>
using namespace std;
int a,b,c,d;
char a1,b1;
int main(){
    freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> a >> c >> a1 >> b >> d >> b1;
	if(a == b){
		cout << 1;
	}
	else{
	cout << "0000";
	return 0;
}

	if(c == d){
		cout << 1;
			}
			else
			cout << 0;
		
			if(c == d){
			   if(a1 == 'A'){
			   if(b1 == 'B' || b1 == 'C')
			   cout << 1;
			   else
			   cout << 0;
		}
		else
		     if(a1 == 'B'){
			   if(b1 == 'A' || b1 == 'C')
			   cout << 1;
			   else
			   cout << 0;
			}else
		     if(a1 == 'C'){
			   if(b1 == 'A' || b1 == 'B')
			   cout << 1;
			   else
			   cout << 0;
			}else
		     if(a1 == 'F'){
			   if(b1 == 'D')
			   cout << 1;
			   else
			   cout << 0;
			}else
		     if(a1 == 'D'){
			   if(b1 == 'F')
			   cout << 1;
			   else
			   cout << 0;
			}
		}
		else
		cout << 0;
		
		if(a1 + 1 == b1&&a1 !='C' && c == d)
		cout << 1;
		else
			if(b1 + 1 == a1&&b1 !='C' && c == d)
		cout << 1;
		else
		cout << 0;
	return 0;
}
