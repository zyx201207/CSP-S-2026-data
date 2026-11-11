#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll c1,c2,n1,n2;
char set1,set2;
string s1,s2;
bool check(){
	ll x=0,y=0;
	if(set1=='A'||set1=='B'||set1=='C'){
		x=1;
	}
	if(set2=='A'||set2=='B'||set2=='C'){
		y=1;
	}
	if(x==y) return 1;
	else return 0;
}
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	n1=ll(s1[0]-'0')*10+ll(s1[1]-'0'),n2=ll(s2[0]-'0')*10+ll(s2[1]-'0');
	set1=s1[2],set2=s2[2];
	if(c1==c2){
		cout<<1;
		if(n1==n2){
			cout<<1;
			if(check()){
				cout<<1;
				if(abs(set1-set2)==1){
					cout<<1;
				}else{
					cout<<0;
				}
			}else{
				cout <<0<<0;
			}
		}else{
			cout<<0<<0<<0;
		}
	}else{
		cout<<0<<0<<0<<0;
	}
	return 0;
} 
