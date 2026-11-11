#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    if(c1==c2) cout<<1;
    else{
		cout<<0<<0<<0<<0;
		return 0;
	}
    if(s1[1]==s2[1]&&s1[0]==s2[0]){
		cout<<1;
    }else{
        cout<<0<<0<<0;
        return 0;
	}
    if(s1[2]>='D'&&s2[2]>='D'){
		cout<<1;
		cout<<1;
		return 0;
	}else if(s1[2]<='C'&&s2[2]<='C'){
		cout<<1;
		if(s1[2]-s2[2]==1||s1[2]-s2[2]==-1){
			cout<<1;
			return 0;
		}
	}else{
		cout<<0;
	}
    cout<<0;
    return 0;
}
