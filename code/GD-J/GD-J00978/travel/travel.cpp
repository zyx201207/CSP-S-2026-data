#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int cnt=0;
bool isp[128];
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	isp['A']=isp['B']=isp['C']=1;
	isp['D']=isp['F']=0;
	if(c1==c2){
		cout<<1;
		cnt++;
		string num1,num2;
		num1+=s1[0];
		num2+=s2[0];
		num1+=s1[1];
		num2+=s2[1];
		if(num1==num2){
			cout<<1;
			cnt++;
			if(!(isp[(int)s1[2]]^isp[(int)s2[2]])){
				cout<<1;
				cnt++;
				if(s1[2]=='D'||s1[2]=='F'){
					cout<<1;
					cnt++;
				}
				else if(abs((int)s1[2]-s2[2])==1){
					cout<<1;
					cnt++;
				}
			}
		}
	}
	while(cnt!=4){
		cout<<0;
		cnt++;
	}
	return 0;
} 
