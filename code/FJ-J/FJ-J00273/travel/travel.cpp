#include<bits/stdc++.h>
using namespace std;
struct b{
	string c,l;
}a[2];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a[0].c>>a[0].l>>a[1].c>>a[1].l;
	if(a[0].c[1]==a[1].c[1] && a[0].c[0]==a[1].c[0]){
		cout<<1;
	}
	else{
		cout<<0<<0<<0<<0;
		return 0;
	}
	if(a[0].l[1]==a[1].l[1] && a[0].l[0]==a[1].l[0]){
		cout<<1;
	}
	else{
		cout<<0<<0<<0;
		return 0;
	}
	if((a[0].l[2]=='A' && a[1].l[2]=='B')||(a[0].l[2]=='B' && a[1].l[2]=='A'))cout<<1<<1;
	else if((a[0].l[2]=='A' && a[1].l[2]=='C')||(a[0].l[2]=='C' && a[1].l[2]=='A'))cout<<1<<0;
	else if((a[0].l[2]=='B' && a[1].l[2]=='C')||(a[0].l[2]=='C' && a[1].l[2]=='B'))cout<<1<<1;
	else if((a[0].l[2]=='D' && a[1].l[2]=='F')||(a[0].l[2]=='F' && a[1].l[2]=='D'))cout<<1<<1;
	else cout<<0<<0;
	return 0;
} 
