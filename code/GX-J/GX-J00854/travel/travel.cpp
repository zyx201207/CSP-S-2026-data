#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<'1';
	}
	else{
		cout<<'0';
	}
	if(s1==s2){
		cout<<'1';
	}
	else{
		cout<<'0';
	}	
	


	fclose(stdin);
	fclose(stdout);
	
    return 0;
}
