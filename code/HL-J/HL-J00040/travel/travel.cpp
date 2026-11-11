#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel","r",stdin);
	freopen("travel","w",stdout);
	int a = 0;
	int b = 0;
	int c = 0;
	int j = 0;
	string c1,s1,c2,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 == c2&&(c1 != "01"&& c1 != "16")){
		cout << 1;
	}
	else{
		cout << 0;
		a++;
	}
	for(int i=0;i<2;i++){
		if(s1[i]==s2[i]){
			j++;
		}
	}
	if(j != 2||a==1){
		cout << 0;
		b++;
	}
	else{
		cout << 1;
	}
	
	if(((s1[2]<='A'&&s1[2]!='A')||s2[2]<'A'||s1[2]>'F'||s2[2]>'F'||s1[2]=='E'||s2[2]=='E')||(s1[2] > 'C'&&s2[2] <= 'C'||s1[2]<'D' && s2[2] >= 'D')||a==1||b==1){
		cout << 0;
		c++;
	}
	else{
		cout << 1;
	}
	if(s1[2]=='A'||a==0||b==0||c==0){
		if(s2[2]=='B'){
			cout << 1;
		}
		else{
		cout << 0;
	    }
	}
	else if(s1[2]=='B'||a==0||b==0||c==0){
		if(s2[2]=='A'||s2[2]=='C'){
			cout << 1;
		}
		else{
		cout << 0;
	    }
	}
	else if(s1[2]=='C'||a==0||b==0||c==0){
		if(s2[2]=='B'){
			cout << 1;
		}
		else{
		cout << 0;
	    }
	}
	else if(s1[2]=='D'||a==0||b==0||c==0){
		if(s2[2]=='E'){
			cout << 1;
		}
		else{
		cout << 0;
	    }
	}
	else if(s1[2]=='E'||a==0||b==0||c==0){
		if(s2[2]=='D'){
			cout << 1;
		}
		else{
		cout << 0;
	    }
	}
	else{
		cout << 0;
	}
	

	return 0;
}
	
