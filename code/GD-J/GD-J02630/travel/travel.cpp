#include<bits/stdc++.h> 
using namespace std;
string c1,s1,c2,s2;
char a[3]={'A','B','C'};
char b[2]={'D','F'};
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	cout<<1;
	string p1=s1.substr(0,2);
	string p2=s2.substr(0,2);
	if(p1!=p2){
		cout<<"000";
		return 0;
	}
	cout<<1;
	int c=0;
	for(int i=0;i<3;i++){
		if(a[i]==s1[2]||a[i]==s2[2]){
			c++;
		}
	}
	if(c==1){
		cout<<"00";
		return 0;
	}
	cout<<1;
	if(s1[2]+1==s2[2]||s2[2]+1==s1[2]){
		cout<<1;
		return 0;
	}
	cout<<0;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
