#include <bits/stdc++.h>
using namespace std;
const int N=1e6+5;
long long c1,c2;
char s1[N],s2[N];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1;
	
	for(int i=1;i<=3;i++){
		cin >> s1[i];
	}
	cin >> c2;
	for(int i=1;i<=3;i++){
		cin >> s2[i];
	}
	if(c1==c2){
		cout << 1;
	}else{
		cout << 0;
	}
	int f=1;
	for(int i=1;i<=2;i++){
		if(s1[i]!=s2[i]){
			f=0;
			cout << 0;
			break;
		}
	}
	if(f==1){
		cout << 1;
	}
	if ((s1[3]=='A' || s1[3]=='B' || s1[3]=='C') && (s1[3]=='A' || s1[3]=='B' || s1[3]=='C')  && s1[3]!=s2[3]){
		cout << 1;
		if((s1[3]=='B' && s2[3]=='C') || (s1[3]=='B' && s2[3]=='A')){
			cout << 1;
		}else if((s1[3]=='A' && s2[3]=='B') || (s1[3]=='C' && s2[3]=='B')){
			cout << 1;
		}else{
			cout << 0;
		}
	}
	else if ((s1[3]=='D' || s1[3]=='F') && (s2[3]=='D' || s2[3]=='F')  && s1[3]!=s2[3]){
		cout << 1;
		cout << 1;
	}
	else {
		cout << 0;
		cout << 0;
	}
	return 0;
	
} 
