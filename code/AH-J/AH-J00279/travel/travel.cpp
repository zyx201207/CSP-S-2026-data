#include<bits/stdc++.h>
#define ll long long
using namespace std;
string c1,s1,c2,s2;
int a1,b1,a2,b2;
char c,d;
bool f;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	for(int i=0;i<c1.size();i++){
		if(c1[i]>='0'&&c1[i]<='9'){
			a1=a1*10+(c1[i]-'0');
		}
	}
	for(int i=0;i<c2.size();i++){
		if(c2[i]>='0'&&c2[i]<='9'){
			a2=a2*10+(c2[i]-'0');
		}
	}
	if(a1==a2){
		cout<<1;
		f=1;
	}
	else    cout<<0;
	
	for(int i=0;i<s1.size();i++){
		if(s1[i]>='0'&&s1[i]<='9'){
			b1=b1*10+(s1[i]-'0');
		}
		else   c=s1[i];
	}
	for(int i=0;i<s2.size();i++){
		if(s2[i]>='0'&&s2[i]<='9'){
			b2=b2*10+(s2[i]-'0');
		}
		else   d=s2[i];
	}
	if(b1==b2&&f==1){
		cout<<1;
	}
	else{
		cout<<0;
		f=0;
	}
	
	if(c>d)	swap(c,d);
	if((c=='A'&&d=='B'||c=='A'&&d=='C'||c=='B'&&d=='C'||c=='D'&&d=='F')&&f==1){
		cout<<1;
	}
	else{
		cout<<0;
		f=0;
	}
	
	if((c=='A'&&d=='B'||c=='B'&&d=='C'||c=='D'&&d=='F')&&f==1){
		cout<<1;
	}
	else{
		cout<<0;
	}
	return 0;
}
/*
17 节车厢 ,其中,01 和 16 号车厢是一等座车厢,其余车厢是二等座车厢

每节二等座车厢共有 18 排,每排有 5 个座位


你需要帮助小 R 依次判断:
• 两张车票对应的座位是否在同一节车厢;
• 两张车票对应的座位是否在同一节车厢的同一排;
• 两张车票对应的座位是否在同一节车厢的同一排,且位于过道的同一侧;
• 两张车票对应的座位是否相邻。




*/
