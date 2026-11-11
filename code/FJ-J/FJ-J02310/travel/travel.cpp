#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	for(ll i=0;i<2;i++){
		if((c1[i]-'0')!=(c2[i]-'0')){
		    cout<<"0000";
		    return 0;
		}	
	}
	cout<<"1";
	for(ll j=0;j<2;j++){
		if((s1[j]-'0')!=(s2[j]-'0')){
			cout<<"000";
			return 0;
		}
	}
	cout<<"1";
	if((s1[2]-'A'<3&&s2[2]-'A'<3)||(s1[2]-'A'>3&&s2[2]-'A'>3)) cout<<"1";
	else{
		cout<<"00";
		return 0;
	}
	if(s1[2]-'A'<3&&s2[2]-'A'<3){
		if(abs((s1[2]-'A')-(s2[2]-'A'))==1) cout<<"1";
		else cout<<"0";
	}
	else{
		if(abs((s1[2]-'A')-(s2[2]-'A'))==2) cout<<"1";
		else cout<<"0";
	}
	return 0;
} 
