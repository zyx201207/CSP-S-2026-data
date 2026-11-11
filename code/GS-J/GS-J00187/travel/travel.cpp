#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	int t=0;
	cin>>c1>>s1>>c2>>s2;
	string w="";
	for(int i=0;i<2;i++){
		if(c1[i]==c2[i]){
			t=1;
		}
		else{
			t=0;
			break;
		}
	}
	if(t==1){
		w+="1";
	}
	else{
		w+="0000";
		cout<<w;
		return 0;
	}
	if(s1[0]==s2[0]){
		if(s1[1]==s2[1]){
			w+="1";
		}
		else{
			w+="000";
			cout<<w;
			return 0;
		}
	}
	else{
		w+="000";
		return 0;
	}
	if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C'){
		if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'){
			w+="1";
			if(s1[2]=='B'||s2[2]=='B'){
				w+="1";
			}
			else{
				w+="0";
				cout<<w;
				return 0;
			}
		}
		else{
			w+="00";
			cout<<w;
			return 0;
		}
	}
	else{
		if(s2[2]=='D'||s2[2]=='F'){
			w+="11";
		}
		else{
			w+="00";
			cout<<w;
			return 0;
		}
	}
	cout<<w<<endl;
	return 0;
}
