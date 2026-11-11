#include<bits/stdc++.h>
using namespace std;
int jx(string s){
	int ans=0;
	ans+=(s[0]-'0')*10;
	ans+=s[1]-'0';
	return ans;
}
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,c;
	string b,d;
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<1;
		int e=jx(b);
		int f=jx(d);
		if(e==f){
			cout<<1;
			char g=b[2];
			char h=d[2];
			if( ((g=='A'||g=='B'||g=='C')&&(h!='D'&&h!='F')) || ((g=='D'||g=='F')&&(h=='D'||h=='F')) ){
				cout<<1;
				if(g+1==h||g-1==h){
					cout<<1;
				}else cout<<0;
			}else cout<<"00";
		}else cout<<"000";
	}
	else cout<<"0000";
	return 0;
} 
