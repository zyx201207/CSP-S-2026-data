#include<bits/stdc++.h>
using namespace std;
int cnt,cnt1;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,c3,c4,s;
	cin>>c1>>c2>>c3>>c4;
	char a=c2[2],b=c4[2];
	if(c1==c3) s+='1';
	else{
		s+="0000";
		cout<<s;
		return 0;
	}
	for(int i=0;i<3;i++){
		int ct=int(c2[i]),ct1=int(c4[i]);
		if(ct>='0'&&ct<='9'){
			cnt*=10;
			cnt+=ct-'0';
		}
		if(ct1>='0'&&ct1<='9'){
			cnt1*=10;
			cnt1+=ct1-'0';
		}
	}
	if(cnt==cnt1){
		s+='1';
		if(((a=='A'||a=='B'||a=='C')&&(b=='A'||b=='B'||b=='C'))||((b=='D'||b=='F')&&(a=='D'||a=='F'))){
			s+='1';
			if(((a=='A'&&b=='B')||(a=='B'&&b=='C')||(a=='D'&&b=='F'))||((b=='A'&&a=='B')||(b=='B'&&a=='C')||(b=='D'&&a=='F'))){
				s+='1';
			}else{
				s+='0';
			}
		}else{
			s+="00";
		}
	}else{
		s+="000";
	}
	cout<<s;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
