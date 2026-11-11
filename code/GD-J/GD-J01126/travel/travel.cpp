#include<bits/stdc++.h>
//#define int long long
#define endl '\n'
using namespace std;
string c1,s1,c2,s2;
int numa,numb;
bool ch1,ch2,ch3;
void init(){
	string a=s1,b=s2;
	a.erase(2,1);
	b.erase(2,1);
	for(int i=0;i<a.size();i++) numa = numa*10 + (a[i]-'0');
	for(int i=0;i<b.size();i++) numb = numb*10 + (b[i]-'0');
	return ;
}
void check1(){
	if(c1 == c2) cout << 1,ch1 = true;
	else cout << 0;
	return ;
}
void check2(){
	if(!ch1){
		cout << 0;
		return ;
	}
	if(numa == numb) cout << 1,ch2 = true;
	else cout << 0;
	return ;
}
void check3(){
	if(!ch2 || !ch1){
		cout << 0;
		return ;
	}
	string da = s1,db = s2;
	da.erase(0,2);
	db.erase(0,2);
	int aleft,bleft;
	if(da == "A" || da == "B" || da == "C") aleft = 1;
	else aleft = 2;
	if(db == "A" || db == "B" || db == "C") bleft = 1;
	else bleft = 2;
	if(aleft == bleft)cout << 1,ch3 = true;
	else cout << 0;
	return ;
}
void check4(){
	if(!(ch1&&ch2&&ch3)){
		cout << 0;
		return ;
	}
	string da = s1,db = s2;
	da.erase(0,2);
	db.erase(0,2);
	//cout << da[0] << " " << db[0];
	if(abs(da[0]-db[0]) == 1) cout << 1;
	else cout << 0;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	init();
	check1();
	check2();
	check3();
	check4();
	return 0;
} 
