#include<bits/stdc++.h>
using namespace std;
bool find(int ss1,int ss2,bool dsa = false){
	/*
	switch(ss1){
		case 'A':
			dsa = (ss2 == 'B') ? true : false;
			break;
		case 'B':
			dsa = (ss2 == 'A' || ss2 == 'C') ? true : false;
			break;
		case 'C':
			dsa = (ss2 == 'B') ? true : false;
			break;
		case 'D':
			dsa = (ss2 == 'F') ? true : false;
			break;
		case 'F':
			dsa = (ss2 == 'D') ? true : false;
			break;
	}
	*/
	if(((ss1 == 'A' || ss1 == 'C') && (ss2 == 'B')) || ((ss1 == 'B') && (ss2 == 'C' || ss2 == 'A')) || ((ss1 == 'D') && (ss2 == 'F')) || ((ss1 == 'F') && (ss2 == 'D'))) dsa = true;
	
	return dsa;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	string a1,s1,a2,s2;
	cin>>a1>>s1;
	cin>>a2>>s2;
	
	bool f[5] = {false};
	int ss1 = s1[2],ss2 = s2[2];
	
	if(a1[0] == a2[0] && a1[1] == a2[1]){
		f[1] = true;
	
		if(s1[0] == s2[0] && s1[1] == s2[1]){
			f[2] = true;
			
			int n1 = (s1[0]-'0')*10 + (s1[1]-'0'),n2 = (s2[0]-'0')*10 + (s2[1]-'0');
			int aa = (ss1-'A'),ss = (ss2-'A');
			int sa = (n1+2)/3,sb = (n2+2)/3;
			if(sa == sb){
				f[3] = true;
				f[4] = find(ss1,ss2);
			}
		}
	}
	
	for(int i = 1;i<=4;i++){
		if(f[i]){
			cout<<1;
		}else{
			cout<<0;
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
