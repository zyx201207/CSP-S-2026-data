#include <bits/stdc++.h>
#define int long long
using namespace std;
string s1,s2,c1,c2;
bool flag,fl1,flag2,flag3;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>c1>>s2>>c2;
	int n=s1.size();
	if(s1==s2){
		cout<<1;
	}else{
		cout<<"0000";
		return 0;
	} 
	for(int i=0;i<c1.size();i++){
		if(i==1){
			//cout<<c1[1]<<c2[1]<<"\n";//
			if(c1[i]==c2[i]){
				cout<<1;
				fl1=1;
			}
		if(fl1==0){
			cout<<"000";
			return 0;
		}
	}
		if(i==2){
		if((c1[i]=='D'||c1[i]=='F')&&(c2[i]=='D'||c2[i]=='F')){
				flag=1;
			}
			if((c1[i]=='A'||c1[i]=='B'||c1[i]=='C')&&(c2[i]=='A'||c2[i]=='B'||c2[i]=='C')){
				flag2=1;
			}
			
			if(((c1[i]=='A'||c1[i]=='C')&&c2[i]=='B')||(c1[i]=='B'&&(c2[i]=='A'||c2[i]=='C'))){
				flag3=1;
			}
		}
	}
	if(flag==1){
		cout<<"11";
		return 0;
	}else{
		if(flag2==0&&flag==0&&flag3==0){
			cout<<"00";
		    return 0;
		}
		
	}
	if(flag2==1)cout<<1;
	else cout<<0;
	if(flag3==1)cout<<1;
	else cout<<0;
	return 0;
}
