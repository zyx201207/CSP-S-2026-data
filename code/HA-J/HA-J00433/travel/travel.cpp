#include<bits/stdc++.h>
using namespace std;

string c1,c2,s1,s2;

int main(){
	freopen("stdin","r",travel.in);
	freopen("stdout","w",travel.out);
	cin>>c1>>s1>>c2>>s2;
	if(c1 != c2){
		cout<<"0000";
	}else{
		cout<<"1";
		string a1,a2;
		a1[0] = s1[0] ; a1[1] = s1[1] ; a2[0] = s2[0] ; a2[1] = s2[1];
		if(a1 != a2){
			cout<<"000";
		}else{
			cout<<"1";
			char aa1 = s1[2],aa2 = s2[2];
			if(aa1 >= 'A' && aa1 <= 'C' && aa2 >= 'A' && aa2 <= 'C'){
				cout<<"1";
			}else if((aa1 == 'D' || aa1 == 'F') && (aa2 == 'D' || aa2 == 'F')){
				cout<<"1";
			}else {
				cout<<"00";
				return 0;
			}
			if(aa1 == 'A' && aa2 == 'B'){
				cout<<"1";
			}else if(aa1 == 'B' && (aa2 == 'A' || aa2 == 'C')){
				cout<<"1";
			}else if(aa1 == 'C' && aa2 == 'B'){
				cout<<"1";
			}else if((aa1 == 'D' || aa1 == 'F') && (aa2 == 'D' || aa2 == 'F')){
				cout<<"1";
			}
		}
	}
	return 0;
} 
