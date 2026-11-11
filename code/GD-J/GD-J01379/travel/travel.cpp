#include<bits/stdc++.h>
using namespace std;
string s="ABC";
string ts="DE";
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); 
	string qs,ws,es,rs;
	cin>>qs>>ws>>es>>rs;
	if(qs==es) cout<<1;
	else{
		cout<<0<<0<<0<<0;
		return 0;
	}
	if(ws[0]==rs[0]&&ws[1]==rs[1]) cout<<1;
	else{
		cout<<0<<0<<0;
		return 0;
	}
	bool qf=0,wf=0;
	for(int i=0;i<3;i++){
		if(s[i]==ws[2]) qf=1;
		if(s[i]==rs[2]) wf=1;
	} 
	//cout<<qf<<" "<<wf<<endl;;
	if(!((qf&&wf)||(!qf&&!wf))) cout<<0<<0;
	else{
		cout<<1;
		if(ws[2]+1==rs[2]||rs[2]+1==ws[2]) cout<<1;
		else cout<<0;
	}
	
	return 0;
}
 
