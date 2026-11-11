#include <bits/stdc++.h>
using namespace std;
string s1,s3;
char s2,s4;
int n,n1;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> s1 >> n >> s2 >> s3 >> n1>> s4;
    if(s1 == s3){
    	cout << 1;
    	if(n == n1){
    		cout <<1;
		}
		else{
			cout <<0;
		}
    	if((s2 == 'D' && s4 == 'F' && n == n1) || (s2 == 'F' && s4 == 'D'&& n == n1)){
			cout << 1;
		}
		else if((s2 == 'A' && s4 == 'B'&& n == n1) || (s2 == 'B' && s4 == 'A'&& n == n1)){
			cout << 1;
		}
		else if((s2 == 'C' && s4 == 'B'&& n == n1) || (s2 == 'B' && s4 == 'C'&& n == n1)){
			cout << 1;
		}
		else if((s2 == 'C' && s4 == 'A'&& n == n1) || (s2 == 'A' && s4 == 'C'&& n == n1)){
			cout <<1;
		}
		else{
			cout <<0;
		}
		
    	if((s2 == 'D' && s4 == 'F'&& n == n1) || (s2 == 'F' && s4 == 'D'&& n == n1)){
			cout << 1;
		}
		else if((s2 == 'A' && s4 == 'B'&& n == n1) || (s2 == 'B' && s4 == 'A'&& n == n1)){
			cout << 1;
		}
		else if((s2 == 'C' && s4 == 'B'&& n == n1) || (s2 == 'B' && s4 == 'C'&& n == n1)){
			cout << 1;
		}
		else{
			cout <<0;
		}			
	}
	else{
		cout <<"0000";
	}
	
    return 0;
}
