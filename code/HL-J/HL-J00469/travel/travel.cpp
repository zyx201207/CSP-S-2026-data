#include<iostream>
using namespace std;
	int a[5];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	char s1[5],s2[5],c1[5],c2[5];
	cin>>s1>>c1>>s2>>c2;
	cout<<s1<<s2<<c1<<c2;	
	if(s1[0]==s2[0]&&s1[1]==s2[1]){
		a[1]=1;
	}
	else{
		cout<<"0000";
		return 0;
	}
	if(c1[0]==c2[0]&&c1[1]==c2[1]){
		a[2]=1;
	}
	else{
		cout<<"1000";
		return 0;
	}
	if(c1[2]=='A'||c1[2]=='B'||c1[2]=='C'&&c2[2]=='A'||c2[2]=='B'||c2[2]=='C'){
		a[3]=1;
	}
	else if(c1[2]=='D'||c1[2]=='F'&&c2[2]=='D'||c2[2]=='F'){
		a[3]=1;
	}
	else{
		cout<<"1100";
		return 0;
	}
	if(c1[2]+1==c2[2]||c1[2]-1==c2[2]){
		a[4]=1;
	}
	else{
		cout<<"1110";
		return 0;
	}
	for(int i=1;i<5;i++){
		cout<<a[i];
	}
	return 0;
}
