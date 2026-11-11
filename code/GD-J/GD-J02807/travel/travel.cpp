#include <bits/stdc++.h>
using namespace std;
#define int long long
/*
同步流怎么关来着.? 
*/
int ans=0;
void cou(){
	int an=4-ans;
	while(ans--){
		cout<<1;
	}while(an--){
		cout<<0;
	}
	return ;
}
signed main(){
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b;
	int aa,bb;
	char c,d;
	cin>>a>>aa>>c>>b>>bb>>d;
//	cerr<<"a的车厢号:"<<a<<" a的排号"<<aa<<" a的座位号"<<c<<endl;
//	cerr<<"b的车厢号:"<<b<<" b的排号"<<bb<<" b的座位号"<<d<<endl;
	if(a==b){
		ans+=1;
	}else{
		cou();
		return 0;
	}
	if(aa==bb){
		ans+=1;
	}else{
		cou();
		return 0;
	}
	if((c=='A'&&(d=='B'||d=='C'))||(c=='B'&&(d=='A'||d=='C'))||(c=='C'&&(d=='A'||d=='B'))||(c=='D'&&d=='F')||(c=='F'&&d=='D')){
		ans+=1;
	}else{
		cou();
		return 0;
	}
	if((c=='A'&&d=='B')||(c=='B'&&(d=='A'||d=='C'))||(c=='C'&&d=='B')||(c=='D'&&d=='F')||(c=='F'&&d=='D')){
		ans+=1;
	}cou();
	return 0;
}
