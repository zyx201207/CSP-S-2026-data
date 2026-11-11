#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	char s1[3],s2[3];
	cin>>c1;
	for(int i=1;i<=3;i++){
		cin>>s1[i];
	}
	cin>>c2;
	for(int i=1;i<=3;i++){
		cin>>s2[i];
	}
	if(c1==c2){
		cout<<"1";
	}
	else{
		cout<<"0000";
		return 0;
	}
	int sum=0;
	for(int i=1;i<=2;i++){
		if(s1[i]==s2[i]){
			sum++;
		}
	}
	if(sum>=2){
		cout<<"1";
	}
	else{
		cout<<"000";
		return 0;
	}
	if(s1[3]== 51 || s1[3]== 50 && s2[3]== 51 || s2[3]== 50 &&  s1[3]== 51 || s1[3]== 49 && s2[3]== 51 || s2[3]== 49 && s1[3]== 51 || s1[3]== 48 && s2[3]== 51 || s2[3]== 48 && s1[3]== 52 || s1[3]== 50 && s2[3]== 52 || s2[3]== 50 && s1[3]== 52 || s1[3]== 49 && s2[3]== 52 || s2[3]== 49 && s1[3]== 52 || s1[3]== 48 && s2[3]== 52 || s2[3]== 48){
		cout<<"00";
		return 0;
	}
	else if(s1[3]-s2[3]==1 ||s1[3]-s2[3]==-1 && s1[3]== 50 ||s2[3] ==48 ||s1[3]==48 || s2[3]==50){
		cout<<"1";
		if(s1[3]-s2[3]==1 ||s1[3]-s2[3]==-1){
			cout<<"1";
		}
		else{
			cout<<"0";
			return 0;
	    }
	}
	else{
		cout<<"00";
		return 0;
	}
} 
