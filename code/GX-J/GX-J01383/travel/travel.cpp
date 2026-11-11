#include<bits/stdc++.h>
using namespace std;
int main(){
	
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    string n,n2;
    string s;
    string s2;
    cin >> n;
    cin >> s;
    cin >> n2;
    cin >> s2;
    if(n[0]==n2[0]&&n[1]==n2[1]){
        cout << "1";
    }
    else{
        cout << "0";
    }
     if(n[0]==n2[0]&&n[1]==n2[1]){
		 if(s[0]==s2[0]&&s[1]==s2[1]){
        cout << "1" ;
    }
    else{
        cout << "0";
    }
    }
    else {
		cout << "0";
	}
    if(n[0]==n2[0]&&n[1]==n2[1]){
		if(s[0]==s2[0]&&s[1]==s2[1]){
			if(s[2]>='D'&&s2[2]>='D'){
				cout << "1";
			}
			else if(s[2]<'D'&&s2[2]<'D'){
				cout << "1";
			}
			else{
				cout << "0";
			}
		}
		else {
			cout << "0";	
		}
    }
    else {
		cout << "0";
		}
	if(n[0]==n2[0]&&n[1]==n2[1]){
       if(s[0]==s2[0]&&s[1]==s2[1]){
		   if(s[2]>='D'&&s2[2]>='D'){
			   cout << "1";
		   }
		   else if(s[2]=='D'&&s2[2]=='C'){
            cout << "0";
           }
           else if(s2[2]=='D'&&s[2]=='C'){
			cout << "0";
			}
        
            else if(s[2]<'D'&&s2[2]<'D'){
				if(s[2]=='A'&&s2[2]=='B'){
					cout << "1";
				}
				else if(s[2]=='B'&&s2[2]=='C'){
					cout << "1";
				}
				else if(s[2]=='B'&&s2[2]=='A'){
					cout << "1";
				}
				else if(s[2]=='C'&&s2[2]=='B'){
					cout << "1";
				}
				else if(s[2]=='B'&&s2[2]=='A'){
					cout << "1";
				}
				else if(s[2]=='C'&&s2[2]=='B'){
					cout << "1";
				}
				else if(s[2]=='A'&&s2[2]=='B'){
					cout << "1";
				}
				else if(s[2]=='B'&&s2[2]=='C'){
					cout << "1";
				}
				else{
					cout << "0";
				}
			}
		}
			else {
					cout << "0";
			}
		}
		else cout << "0";
    return 0;
}
