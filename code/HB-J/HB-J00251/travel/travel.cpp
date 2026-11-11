#include<bits/stdc++.h>
using namespace std;

int c1,c2;
int s1,s2;
char l1,l2;
int ce[]={0,1,1,1,2,0,2};

bool same_box(){
	return c1==c2;
}
bool same_p(){
	if(same_box())
		return s1==s2;
	else return false;
}

bool same_ce(){
	if(same_p())
		return ce[int(l1)-64]==ce[int(l2)-64];
	else return false;
}

bool xl(){
	int x=ce[int(l1)-64],y=ce[int(l2)-64];
	if(!same_ce())return false;
	
	if(x==2&&y==2)return true;
	if(abs((int(l1)-64)-(int(l2)-64))==1)
		return true;
	return false;
}

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	cin>>c1>>s1>>l1>>c2>>s2>>l2;
	
	//~ printf("%d %d%c %d %d%c",c1,s1,l1,c2,s2,l2);
	
	cout<<same_box()<<same_p()<<same_ce()<<xl();
	
	return 0;
}
