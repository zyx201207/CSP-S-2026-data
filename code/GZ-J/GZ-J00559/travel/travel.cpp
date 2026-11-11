//GZ-J00559 遵义市第十二中学 李承昊 
#include<bits/stdc++.h>
using namespace std;
char a[3],b[3],c[4],d[4];
int ca,cb,sa,sb;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>c>>b>>d;
	ca=(a[0]-'0')*10+(a[1]-'0'),cb=(b[0]-'0')*10+(b[1]-'0');
	if(ca==cb) cout<<1;
	else{
		cout<<"0000";
		return 0;
	}
	sa=(c[0]-'0')*10+(c[1]-'0'),sb=(d[0]-'0')*10+(d[1]-'0');
	if(sa==sb) cout<<1;
	else{
		cout<<"000";
		return 0;
	}
	sa=c[2],sb=d[2];
	if(sa<=67&&sb>67 || sa>67&&sb<=67){
		cout<<"00";
		return 0;
	} 
	else cout<<1;
	int cnt=abs(sa-sb);
	if(cnt==1) cout<<1;
	else cout<<0;
	return 0;
}
