#include<bits/stdc++.h>
using namespace std;
int t1,t2,s1,s2;
char c1,c2;
bool f1,f2,f3,f4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr); 
	
	cin>>t1>>s1>>c1>>t2>>s2>>c2;
	f1=(t1==t2);
	cout<<f1;
	f2=(f1&&(s1==s2));
	cout<<f2;
	f3=(f2&&!(c1>='A'&&c1<='C'&&c2>='D'&&c2<='F'||c2>='A'&&c2<='C'&&c1>='D'&&c1<='F'));
	cout<<f3;
	f4=(f3&&((abs(int(c1-c2))==1)||c1=='D'&&c2=='F'||c1=='F'&&c2=='D'));
	cout<<f4;
	
	return 0;
} 
