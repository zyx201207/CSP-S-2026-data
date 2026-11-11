#include <bits/stdc++.h>
using namespace std;
char x1,x2,s1,s2,a1,y1,y2,s3,s4,b1;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> x1 >> x2 >> s1 >> s2 >> a1 >> y1>>y2 >> s3 >> s4 >> b1;
	int x = (x1-'0')*10+x2-'0';
	int y = (y1-'0')*10+y2-'0';
	int s = (s1-'0')*10+s2-'0';
	int s5 = (s3-'0')*10+s4-'0';
    if(x!=y){
    	cout << "0000";
    	return 0;
	}
	if(s!=s5){
		cout << "1000";
		return 0;
	}
	if(((a1>='A'&&a1<='C')&&(b1>='A'&&b1<='C'))||((a1>='D'&&a1<='F')&&(b1>='D'&&b1<='F'))){
		cout << "111";
		if(a1+1==b1||b1+1==a1){
			cout << '1';
		}
		else{
			cout << '0';
		}
	}
	else{
		cout << "1100";
	}
		
	return 0;

}
