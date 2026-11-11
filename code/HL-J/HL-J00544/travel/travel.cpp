#include<bits/stdc++.h>
using namespace std;
string a,b;
int c,d,a1,b1;
char x,y;
bool f,p,q;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c>>a>>d>>b;
	if(c==d){
		q=1;
		cout<<1;
	}
	else cout<<0;
	for(int i=0;i<a.size();i++){
		if(a[i]<='9'&&a[i]>='0'){
			a1*=10;
			a1+=a[i]-'0';
		}
		else x=a[i];
	}
	int cnt=0;
	for(int i=0;i<b.size();i++){
		if(b[i]<='9'&&b[i]>='0'){
			b1*=10;
			b1+=b[i]-'0';
		}
		else y=b[i];
	}
	if(a1==b1&&q==1){
		f=1;
		cout<<1;
	}
	else cout<<0;
	if(f==1 && (x<='C'&&y<='C' || x>='D'&&y>='D')){
		p=1;
		cout<<1;
	}
	else cout<<0;
	
	if(p==1 && abs(x-y)==1) cout<<1;
	else cout<<0;
	return 0;
}
