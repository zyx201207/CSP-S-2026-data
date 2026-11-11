#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
int c1,c2,s1,s2;
char ch1,ch2;
int getside(char c){
	if(c=='A'||c=='B'||c=='C')return 1;
	else return 2;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>c1>>s1>>ch1>>c2>>s2>>ch2;
	if(c1==c2){
		cout<<"1";
		if(s1==s2){
			cout<<"1";
			if(getside(ch1)==getside(ch2)){
				cout<<"1";
				if(ch1+1==ch2||ch2+1==ch1){
					cout<<"1";
				}else cout<<"0";
			}else cout<<"00";
		}else cout<<"000";
	}else cout<<"0000";
	return 0;
}

