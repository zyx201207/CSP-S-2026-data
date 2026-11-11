#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string h1,h2,l1,l2;
	cin>>h1>>h2>>l1>>l2;
	if(h1==l1)cout<<1;
	else{
		cout<<0<<0<<0<<0;
		return 0;
	} 
	char h2_w,l2_w;
	h2_w=h2[2];
	l2_w=l2[2];
	h2[2]='0';
	l2[2]='0';
	if(h2==l2)cout<<1;
	else{
		cout<<0<<0<<0;
		return 0;
	} 
	int h2_iw=h2_w-'A'+1;
	int l2_iw=l2_w-'A'+1;
	if((h2_iw<=3 and l2_iw<=3) or (h2_iw>=4 and l2_iw>=4))cout<<1;
	else{
		cout<<0<<0;
		return 0;
	} 
	if(h2_iw+1==l2_iw or h2_iw-1==l2_iw)cout<<1;
	else cout<<0;
	return 0;
} 
