#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string n1,n2;
	string s1,s2;
	cin >> n1 >> s1;
	cin >> n2 >> s2;
	int numa = (n1[0]-'0')*10+(n1[1]-'0');
	int numb = (n2[0]-'0')*10+(n2[1]-'0');
	int numc = (s1[0]-'0')*10+(s1[1]-'0');
	int numd = (s2[0]-'0')*10+(s2[1]-'0');
	if(numa == numb){
		cout << 1;
		if(numc == numd){
			cout << 1;
			if(((s1[2]=='A' || s1[2]=='B' || s1[2]=='C') && (s2[2]=='A' || s2[2]=='B' || s2[2]=='C'
			)) || ((s1[2]=='E' || s1[2]=='F') && (s2[2]=='E' || s2[2]=='F'))){
				cout << 1;
				if((s1[2]=='A' && s2[2]=='B') || (s1[2]=='B' && s2[2]=='C') || (s2[2]=='B' && s1[2]=='C') || (s2[2]=='B' && s1[2]=='C') || (s1[2]=='E' || s2[2]=='F') || (s2[2]=='E' || s1[2]=='F')){
					cout << 1;
				}else{
					cout << 0;
				}
			}else{
				cout << 0 << 0;
			}
		}else{
			cout << 0 << 0 << 0;
		}
	}else{
		cout << 0 << 0 << 0 << 0;
	}
	
} 
