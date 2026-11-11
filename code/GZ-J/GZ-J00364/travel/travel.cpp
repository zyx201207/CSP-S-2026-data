 #include <bits/stdc++.h>
 using namespace std;
 char b[3],d[3];
 int a,c;
 int main(){
 	freopen("treavel.in","r",stdin);
 	freopen("travel.out","w",stdout);
 	cin>>a>>b>>c>>d;
 	if(a!=c){
 		cout<<"0000";
 		return 0;
	 }else if(!(b[0]==d[0])||!(b[1]==d[1])){
		cout<<"1000";
		return 0;
	 }else if((!b[2]<='C'&&d[2]>'C'||b[2]>'C'&&d[2]<='C')){
	 	cout<<"1100";
	 }else if(!(b[2]+1==d[2]||b[2]-1==d[2])){
	 	cout<<"1110";
	 	return 0;
	 }else{
	 	cout<<"1111";
	 }
 	return 0;
 }
