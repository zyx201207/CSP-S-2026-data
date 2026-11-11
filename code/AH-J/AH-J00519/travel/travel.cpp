#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	bool isb = 0;
	if(c1==c2){
		isb = 1;
		cout << 1;
	}else{
		cout << 0;
	}
	int line1 = (s1[0]-48)*10 + (s1[1]-48)*10;
	int line2 = (s2[0]-48)*10 + (s2[1]-48)*10;
	if(line1==line2 && isb) cout<<1;
	else cout<<0;
	
	char jx = s1[2];
	int jx1 = 1;
	if(jx == 'A' or jx == 'B' or jx == 'C') jx1 = 1;
	else jx1 = 2;
	
	int jy1 = 1;
	char jy = s2[2];
	if(jy == 'A' or jy == 'B' or jy == 'C') jy1 = 1;
	else jy1 = 2;
	
	if(jx1 == jy1 && line1 == line2  && c1==c2) cout<<1;
	else cout<<0;
	
	if(jx == 'A' && jy == 'B' && line1 == line2 && isb || jx == 'B' && jy == 'A' && line1 == line2 && isb){
		cout<<1;
		return 0;
	}
	if(jx == 'C' && jy == 'B'  && line1 == line2  && isb || jx == 'B' && jy == 'C'  && line1 == line2 && isb){
		cout<<1;
		return 0;
	}
	if(jx == 'D' && jy == 'F'  && line1 == line2  && isb || jx == 'F' && jy == 'D'  && line1 == line2 && isb){
		cout<<1;
		return 0;
	}
	cout<<0;
	return 0;
	fclose(stdin);
	fclose(stdout);
}
