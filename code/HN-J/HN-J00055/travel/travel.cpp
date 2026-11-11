#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2;
	int c=4,c1,c2; 
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1==c2){
		cout << 1;
		c--;
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<< 1;
			c--;
			if(!(('D'<=s1[2]&&s2[2]<='C')||('D'<=s2[2]&&s1[2]<='C'))){
				cout << 1;
				c--;
				char a=s2[2]-1,b=s2[2]+1;
				if(s1[2]==a||s1[2]==b){
					cout << 1; 
					c--;	
				} 
			}
		}
	}
	for(int i=1;i<=c;i++){
		cout << 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
