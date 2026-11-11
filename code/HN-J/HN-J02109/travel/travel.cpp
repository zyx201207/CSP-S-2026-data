#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char a[5],b[5],c[5],d[5];
	for(int i=1;i<=2;i++){
		cin>>a[i];
	}
	for(int f=1;f<=3;f++){
		cin>>b[f];
	}
	for(int j=1;j<=2;j++){
		cin>>c[j];
	}
	for(int n=1;n<=3;n++){
		cin>>d[n];
	}
	for(int g=1;g<=2;g++){
		if(a[g]!=c[g]){
			cout<<"0000";
			return 0;
	}
	}
	cout<<"1";
		if(b[1]==d[1]&&b[2]==d[2]){
			cout<<"1";
			if(b[3]=='A'&&d[3]=='B'||b[3]=='B'&&d[3]=='A'||b[3]=='C'&&d[3]=='B'||b[3]=='B'&&d[3]=='C'||b[3]=='D'&&d[3]=='E'||b[3]=='E'&&d[3]=='D'){
				cout<<11;
			}else if(b[3]=='A'&&d[3]=='C'||b[3]=='C'&&d[3]=='A'){
			cout<<"10";
			}else{
				cout<<"00";
			}
}else{
	cout<<"000";
}
	return 0;
}
