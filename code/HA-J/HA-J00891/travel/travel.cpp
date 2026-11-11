#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2,l1,l2;
	int c;
	cin >> c1 >> s1 >> c2 >> s2;
	for(int i=0;i<=1;i++){
		l1+=s1[i];
		l2+=s2[i];
	}
	if(c1 == c2){
		cout << 1;
	}
	else{
		cout << 0;
	}
	if(l1 == l2){
		cout << 1;
	}
	else{
		cout << 0;
	}
	if(s1[2]=='D'&&s2[2]=='C'||s1[2]=='C'&&s2[2]=='D'){
		c=0;
		cout << 0;
	}
	else{
		c=1
		cout << 1;
	}
	if((s1[2] == s2[2]+1||s2[2] == s1[2]+1)&&c==1){
		cout << 1;
	}
	else{
		cout << 0;
	}
	fclose(stdin);
	fclose(stdout);
		return 0;
}
