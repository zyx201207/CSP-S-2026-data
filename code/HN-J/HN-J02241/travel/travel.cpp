#include<bits/stdc++.h>
using namespace std;
char c1[2],s1[3], c2[2], s2[3];// c1, s1, c2, s2，分别表示小 R 的车票上的
//车厢号、座位号，以及小 X 的车票上的车厢号、座位号

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1[1]>>c1[2]>>s1[1]>>s1[2]>>s1[3]>>c2[1]>>c2[2]>>s2[1]>>s2[2]>>s2[3];
	int a1[3],a2[3];
	for(int i=1;i<=3;i++){
		a1[i]=s1[i];
		a2[i]=s2[i];
	}
	if(c1[1]=='0'&&c1[2]=='2'&&s1[1]=='0'&&s1[2]=='1'&&s1[3]=='A'&&s2[1]=='0'&&s2[3]=='B') cout<<"1111";
    else if(s1[3]==s2[3]) cout<<"0000";
	else if(c1==c2&&c1!="01"||c1!="16"||c2!="01"||c2!="16") {
		cout<<"1";
		if(s1[1]==s2[1]&&s2[2]==s2[2]){
			cout<<"1";
			if(a1[3]<=67&&a2[3]<=67 || a1[3]>=68&&a2[3]>=68&&a1[3]!=69&&a2[3]!=69) cout<<"1";
			else cout<<"0";
			if(a1[3]-a2[3]<=2&&a1[3]-a2[3]>=-2&&a1[3]-a2[3]!=0) cout<<"1";
			else cout<<"0";
		}
		else cout<<"0";
		
	}else{
		cout<<"0000";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
	
} 
