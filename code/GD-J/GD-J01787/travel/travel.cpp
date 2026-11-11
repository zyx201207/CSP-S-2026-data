#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout); 
	int c1,c2;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)cout<<'1';
	else cout<<'0';
	if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1])cout<<'1';
	else cout<<'0';
	if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1]){
		if((s1[2]-'A'<=2&&s2[2]-'A'<=2)||(s1[2]-'A'>2&&s2[2]-'A'>2)){
			cout<<'1';
		}
		else cout<<'0';
	}
	else cout<<'0';
	bool ok = false;
	int x1 = (s1[0]-'0')*10+s1[1]-'0',x2=(s2[0]-'0')*10+s2[1]-'0';
	int y1 = s1[2]-'A',y2 =s2[2]-'A';
	for(int i = 0;i<4;i++){
		if(x1+dx[i]==x2&&y1+dy[i]==y2){
			ok=true;
			break;
		} 
	}
	if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1]&&ok&&(s1[2]-'A'<=2&&s2[2]-'A'<=2)||(s1[2]-'A'>2&&s2[2]-'A'>2))cout<<'1';
	else cout<<'0';
} 
