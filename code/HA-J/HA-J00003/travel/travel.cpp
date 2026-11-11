#include<bits/stdc++.h>
using namespace std;
struct piao{
	int x;
	int p;
	char w;
};
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	piao a,b;
	bool c[4];
	c[1]=c[2]=c[3]=c[4]=true;
	cin>>a.x>>a.p>>a.w>>b.x>>b.p>>b.w;
	if(a.x!=b.x){
	
		cout<<"0";
		c[1]=0;
	}else cout<<'1';
	if(a.p!=b.p||c[1]==0){
		cout<<"0";
		c[2]=0;
	}
	else cout<<'1';
	if(c[2]==1&&((a.w=='A'||a.w=='B'||a.w=='C')&&(b.w=='A'||b.w=='B'||b.w=='C'))
	||(a.w=='D'||a.w=='F')&&(b.w=='D')||(b.w=='F'))cout<<'1';
	else{
		cout<<"0";
		c[3]=0;
	}
	if(abs(a.w-b.w)==1&&c[3]==1)cout<<'1';
	else cout<<'0';
	return 0;
}
