#include<bits/stdc++.h>
using namespace std;
int c1,c2,r1,r2,l1,l2;
string s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >>c1 >> s1 >>c2 >>s2;
	int l1=s1.length(),l2=s2.length();
	for(int i = 0;i<l1;i++){
		if('0'<=s1[i]&&s1[i]<='9') r1=r1*10+s1[i]-'0';
		else if(s1[i]=='F') l1=5;
		else if('A'<=s1[i]&s1[i]<='D') l1=s1[i]-'A'+1;
	}
	for(int i = 0;i<l2;i++){
		if('0'<=s2[i]&&s2[i]<='9') r2=r2*10+s2[i]-'0';
		else if(s2[i]=='F') l2=5;
		else if('A'<=s2[i]&&s2[i]<='D')l2=s2[i]-'A'+1;
	}
//	cout << r1 << " " << l1 << " " << r2 << " " <<l2 << "\n";
	if(c1==c2){
		cout << 1;
		if(r1==r2){
			cout << 1;
			if((l1<=3&&l2<=3)||(l1>3&&l2>3)){
				cout << 1;
				if(abs(l1-l2)<=1) cout << 1;
				else cout << 0;
			}else{
				cout << "00";
			}
		}else{
			cout << "000";
		}
	}else{
		cout << "0000";
	}
}
