#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,r1,c2,r2;
	cin >> c1 >> c2 >> r1 >> r2;
	int ans1=0,ans2=0;
	string s="";
	for(int i=c1.size()-1; i>=0; i--){
		ans1=ans1*10+c1[i]-'0';
	}
	for(int i=r1.size()-1; i>=0; i--){
		ans2=ans2*10+r1[i]-'0';
	}
	if(ans1!=ans2){
		cout << "0000";
		return 0;
	}
	int sum1=0,sum2=0;
	for(int i=c2.size()-2; i>=0; i--){
		sum1 +=sum1*10+c2[i]-'0';
	}
	for(int i=r2.size()-2; i>=0; i--){
		sum2 +=sum2*10+r2[i]-'0';
	}
	if(sum1!=sum2){
		cout << "1000";
		return 0;
	}
	if((c2[2]<='C' && r2[2]<='C') || (c2[2]>'C' && r2[2]>'C')){
		if(abs(c2[2]-r2[2])<=1){
			cout << "1111";
		}else{
			cout << "1110";
		}
	}else{
		cout << "1100";
	}
	return 0;
} 
