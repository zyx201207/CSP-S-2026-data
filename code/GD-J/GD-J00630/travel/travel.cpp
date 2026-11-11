#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define st string
st s,c,s1,c1;
ll ans,w=1;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>s>>c1>>s1;
	if(c==c1)
		cout<<1;
	else{
		cout<<0;
		w=0;
	}
	for(ll i=0;i<s.size()-1;i++){
		if(s[i]==s1[i])
			ans++;
	}
	if(ans<2||w==0){
		cout<<0;
		w=0;
	}else
		cout<<1;
	if((s[2]>='D'&&s1[2]<'D')||(s[2]>'C'&&s1[2]<='C')||(s[2]<'D'&&s1[2]>='D')||(s[2]<='C'&&s1[2]>'C')||w==0){
		cout<<0;
		w=0;
	}else
	cout<<1;
	if(w!=0&&((char(s[2]+1)==s1[2]&&s[2]!='C')||(char(s1[2]+1)==s[2]&&s1[2]!='C'))){
		cout<<1;
	}else
		cout<<0;
	return 0;
}  
