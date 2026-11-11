//GZ-J00145 贾景栎 遵义市第四中学
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stout);
	string c1,c2,s1,s2;
	int a[10010],cnt=0,b[10010],cntt=0,k=0,l=0,v=0,f=0;
	cin>>c1>>c2>>s1>>s2;
	if(c1==s1){
        cout<<1;
        l=1;
	}
	else cout<<0;
	for(int i=0;i<2;i++){
		cnt+=c2[i]-'0';
		cntt+=s2[i]-'0';
	}
	if(cnt==cntt&&l==1){
        cout<<1;
        v=1;
	}
	else cout<<0;
	char c,d;
	c=c2[2];
	d=s2[2];
	if(((c<='C'&&d<='C')||(c>='D'&&d>='D'))&&v==1){
		cout<<1;
		k=1;
	}
	else cout<<0;
	if((c-d==1||d-c==1)&&k==1)cout<<1;
	else cout<<0;
	return 0;
}
