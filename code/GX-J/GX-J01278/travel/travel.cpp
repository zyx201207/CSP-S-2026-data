#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen ("travel.in","r",stdin);
	freopen ("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1[1]==s1[1]&&c1[2]==s1[2]){
		cout<<1;
	}else{
		cout<<0;
	}
	if(c2[1]==s2[1]&&c2[2]==s2[2]){
		cout<<1;
	}else{
		cout<<0;
	}
	
	fclose (stdin);
	fclose (stdout);
	return 0;
}

