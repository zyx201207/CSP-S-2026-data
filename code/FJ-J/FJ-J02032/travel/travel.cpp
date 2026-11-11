#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=1e5+5;
ll c1, c2;
string s1, s2;
int main(){
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin>>c1>>s1>>c2>>s2;
	bool f1=false, f2=false, f3=false, f4=false;
	int pai1=stoi(s1.substr(0, 2));
	int pai2=stoi(s2.substr(0, 2));
	char i1=s1[2], i2=s2[2];
	if(c1==c2){
		f1=true;
		if(pai1==pai2){
			f2=true;
			if((i1>='D'&&i2>='D')||(
			i1<='C'&&i2<='C')){
				f3=true;
				if((pai1+1==pai2)
				||(pai1-1==pai2)||
				(i1+1==i2)||
				(i1-1==i2)){
					f4=true;
				}
			}
		}
	}
	cout<<f1<<f2<<f3<<f4;
	return 0;
} 
