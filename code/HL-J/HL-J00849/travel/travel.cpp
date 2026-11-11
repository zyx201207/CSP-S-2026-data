#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	cout<<1;
	for(int i=0;i<=1;i++){
		if(s1[i]!=s2[i]){
			cout<<"000";
			return 0;
		}
	}
	cout<<1;
	char c=s1[2];
	char cc=s2[2];
	if(c>cc)swap(c,cc);
	if(c=='A'&&cc=='B'){
		cout<<1<<1;
		return 0;
	}
	if(c=='B'&&cc=='C'){
		cout<<1<<1;
		return 0;
	}
	if(c=='D'&&cc=='F'){
		cout<<1<<1;
		return 0;
	}
	if((c<'D'&&cc<'D')||(c>'D'&&cc>'D')){
		cout<<"10";
		return 0;
	}
	cout<<"00";
	return 0;
}