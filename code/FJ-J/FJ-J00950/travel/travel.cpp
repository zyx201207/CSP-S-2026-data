#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=235299;
signed main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,aa,bb;
	cin>>a;
	cin>>aa;
	cin>>b;
	cin>>bb;
	int flag=0;
	for(int i=0;i<a.size();i++){
		if(a[i]!=b[i])flag=1;
	}
	if(flag==0)cout<<1;
	else{
		cout<<"0000";
		return 0;
	}
	if(aa[0]==bb[0]&&aa[1]==bb[1]){
		cout<<1;
	}
	else{
		cout<<"000";
		return 0;
	}
	if((aa[2]<='C'&&bb[2]<='C')||(aa[2]>'C'&&bb[2]>'C')){
		cout<<1;
	}
	else{
		cout<<"00";
		return 0;
	}
	int c=max(aa[2]-bb[2],bb[2]-aa[2]);
	if(c==1){
		cout<<1;
	}
	else{
		cout<<0;
	}
	return 0;
}
