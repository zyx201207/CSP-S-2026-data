#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2,h1,h2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
	}
	else{
		cout<<"1";
		for(int i=0;i<2;i++){
			h1+=s1[i];
			h2+=s2[i];
		}
		if(h1!=h2){
			cout<<"000";
		}
		else{
			cout<<"1";
			if(s1[2]<='C'&&s2[2]<='C'){
				cout<<"1";
				if(max(s1[2],s2[2])-1==min(s1[2],s2[2])){
					cout<<"1";
				}
				else cout<<"0";
			}
			else if(s1[2]>='D'&&s2[2]>='D'){
				cout<<"1";
				if(s1[2]!=s2[2]){
					cout<<"1";
				}
				else cout<<"0";
			}
			else cout<<"00";
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

