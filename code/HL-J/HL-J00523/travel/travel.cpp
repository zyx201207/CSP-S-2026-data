#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int flag[10]={0};
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin>>c1>>s1>>c2>>s2;
	long long c11=stoi(c1);
	long long c22=stoi(c2);
	long long s11=int(s1[2]-'0');
	long long s22=int(s2[2]-'0');
	if(c11==c22){
		flag[1]=1;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1]&&flag[1]==1){
		flag[2]=1;
	}
	if(flag[2]==1){
		char x=s1[2],y=s2[2];
		if(x=='A'&&(y=='B'||y=='C')){
			flag[3]=1;
		}
		else if(x=='B'&&(y=='A'||y=='C')){
			flag[3]=1;
		}
		else if(x=='C'&&(y=='A'||y=='B')){
			flag[3]=1;
		}
	}
	if(abs(s11-s22)==1&&flag[1]==1&&flag[2]==1&&flag[3]==1){
		flag[4]=1;
	}
	for(int i=1;i<=4;i++){
		cout<<flag[i];
	}
	cout<<endl;
	return 0;
}