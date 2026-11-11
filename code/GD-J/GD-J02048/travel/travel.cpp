#include<bits/stdc++.h>
#define int long long
using namespace std;
map<string,int>mp;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c,s,cx,ss;
	cin>>c>>s>>cx>>ss;
	mp[c]=1;
	int pa=0,pb=0;
	for(int i=0;i<s.size()-1;i++){
		pa=10*pa+(s[i]-'0');
		pb=10*pb+(ss[i]-'0');
	}
	if(mp[cx]==1){
		cout<<1;
		if(pa==pb){
			cout<<1;
			if((s[2]<='C'&&ss[2]<='C')||(s[2]>='D'&&ss[2]>='D')){
				cout<<1;
				if(s[2]+1==ss[2]||s[2]-1==ss[2]){
					cout<<1;
				}else{
					cout<<0;
				}
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
			return 0;
		}
	}
	else{
		cout<<"0000";
		return 0;
	}
	return 0;
} 
