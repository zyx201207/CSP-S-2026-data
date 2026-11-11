#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
string c1,s1,c2,s2;
bool flag=0,flag1=0,flag2=0,flag3=0;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
    cin.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		flag=1;
		cout<<1;
	}else{
		cout<<0;
	}
	int f=(s1[0]-'0'),f1=(s1[1]-'0'),f2=(s2[0]-'0'),f3=(s2[1]-'0');
	f1=f*10+f1;
	f3=f2*10+f3;
	if(f1==f3&&flag==1){
		flag1=1;
		cout<<1;
	}else{
		cout<<0;
	}
	char so=s1[2],so1=s2[2];
	if(so=='A'&&flag1==1){
		if(so1=='B'||so1=='C'){
			flag2=1;
			cout<<1;
		}else{
			cout<<0;
		}
	}
	if(so=='B'&&flag1==1){
		if(so1=='A'||so1=='C'){
			flag2=1;
			cout<<1;
		}else{
			cout<<0;
		}
	}
	if(so=='C'&&flag1==1){
		if(so1=='A'||so1=='B'){
			flag2=1;
			cout<<1;
		}else{
			cout<<0;
		}
	}
	if(flag1==0){
		cout<<0;
	}
	if(flag2==1){
		if(so=='A'&&so1=='B'){
			cout<<1;
			return 0;
		}else{
			flag3=1;
		}
		if(so=='B'){
			if(so1=='A'||so1=='C'){
				cout<<1;
				return 0;
			}
		}else{
			flag3=1;
		}
		if(so=='C'){
			if(so1=='B'){
				cout<<1;
				return 0;
			}
		}else{
			flag3=1;
		}
		if(so=='C'){
			if(so1=='D'){
				cout<<1;
				return 0;
			}
		}else{
			flag3=1;
		}
	}else{
		cout<<0;
	}
	if(flag3==1)cout<<0;
	return 0;
} 

