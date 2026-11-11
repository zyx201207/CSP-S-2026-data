//GZ-J00341 遵义市第四初级中学 彭钰尧
#include <bits/stdc++.h>
using namespace std;
int main(){
	string c1,s1,c2,s2;
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	fclose(stdin);
	fclose(stdout);
	string a="0,1";
	string b="1,6";
	if(c1==c2&&c1!=a&&c1!=b){
		cout<<"1\n";
	}else{
		cout<<"0\n";
	}
	if(s1[1]==s2[1]){
		cout<<"1\n";
	}else{
		cout<<"0\n";
	}
	if(s1[2]>='A'&&s1[2]<='C'){
		cout<<"1\n";
		if(s1[2]=='A'&&s2[2]=='B'){
			cout<<"1\n";
		}else if(s1[2]=='B'){
			cout<<"1\n";
		}else if(s1[2]=='C'&&s2[1]=='B'){
			cout<<"1\n";
		}else{
			cout<<"0\n";
		}
	}else if(s1[2]>='D'&&s1[2]<='E'){
		cout<<"1\n";
		if(s1[2]=='D'&&s2[2]=='E'){
			cout<<"1\n";
		}else{
			cout<<"0\n";
		}
	}else{
		cout<<"0\n";
	}
	return 0;
}
