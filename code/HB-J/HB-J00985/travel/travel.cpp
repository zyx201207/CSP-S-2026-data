#include<bits/stdc++.h>

using namespace std;

int n;
int A = 1,B = 2,C = 3,D = 4,F = 5;

int main(){
	freopen("travel.in","r",stdin);
	//freopen("travel1_ex.in","r",stdin);
	freopen("travel.out","W",stdout);
	
	char c1[20],s1[100],c2[100],s2[100];
	for(int i=1;i<=10;i++){
		cin>>c1[i];
	}
	for(int i=1;i<=10;i++){
		cin>>s1[i];
	}
	for(int i=1;i<=10;i++){
		cin>>c2[i];
	}
	for(int i=1;i<=10;i++){
		cin>>s2[i];
	}
	if(c1[1] == c2[1] && c1[2] == c2[2])
	{
		cout<<"1";
	}
	else cout<<"0";
	if(s1[1] == s2[1] && s1[2] == s2[2]){
		 cout<<"1";
    }
	else cout<<"0";
	if(s1[3] != 5 && s1[3] != 4 && s2[3] != 5 && s2[3] != 4){
		cout<<"1";
	}
	else if(s1[3] != 1 && s1[3] != 2 && s1[3] != 3 && s2[3] != 1 && s2[3] != 2 && s2[3] != 3)
	{
		cout<<"1";
	}
	else cout<<"0";
	if(s1[3] == 1 && s2[2] == 2){
		cout<<"1";
	}
	if(s1[3] == 2 && s2[2] == 1){
		cout<<"1";
	}
	if(s1[3] == 2 && s2[2] == 3){
		cout<<"1";
	}
	if(s1[3] == 3 && s2[2] == 2){
		cout<<"1";
	}
	if(s1[3] == 4 && s2[2] == 5){
		cout<<"1";
	}
	if(s1[3] == 5 && s2[2] == 4){
		cout<<"1";
	}
	else cout<<"0";
	return 0;
}
