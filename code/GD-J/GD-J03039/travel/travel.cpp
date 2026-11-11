#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	string c1,s1,c2,s2;cin>>c1>>s1>>c2>>s2;
	string a="1",b="0";
	int sum=0;
	if(c1==c2){
		cout<<a;
		sum++;
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<<a;
			sum++;
			if('A'<=s1[2]<='C'&&'A'<=s2[2]<='C'){
				cout<<a;
				sum++;
				if((s1[2]-1==s2[2]||s1[2]+1==s2[2])&&s1[2]!='C'&&s2[2]!='D'&&s1[2]!='D'&&s2[2]!='C'){
					cout<<a;
					sum++;
				}
			}if((s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D')){
				cout<<a;
				sum++;
			}
		}
	}
	for(int i=1;i<=4-sum;i++)cout<<b;
	return 0;
}
