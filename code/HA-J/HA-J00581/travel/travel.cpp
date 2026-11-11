#include<bits/stdc++.h>
using namespace std;

int c1,c2;
string s1,s2;

int d1,d2;
char e1,e2;

bool ans[4];

bool side(char h, bool mode = false, char h2 = '-'){
	if(mode){
		if(side(h) == side(h2)){
			int x1 = h-'A';
			int x2 = h2-'A';
			if(h == 'F') x1--;
			if(h2 == 'F') x2--;
			return (x1-x2 == 1)||(x2-x1 == 1);
		}
		return false;
	}else{
		return h > 'C';
	}
}

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout); 
	
	cin >> c1 >> s1 >> c2 >> s2;
	
	d1 = (s1[0]-'0')*10+(s1[1]-'0');
	e1 = s1[2];
	
	d2 = (s2[0]-'0')*10+(s2[1]-'0');
	e2 = s2[2];
	
	if(c1 == c2){
		ans[0] = true;
		if(d1 == d2){
			ans[1] = true;
			if(side(e1) == side(e2)){
				ans[2] = true;
				if(side(e1,1,e2)) ans[3] = true;
			}
		}
	}
	
	for(int i = 0; i < 4; i++){
		printf("%d",ans[i]);
	}
	
	return 0;
}
