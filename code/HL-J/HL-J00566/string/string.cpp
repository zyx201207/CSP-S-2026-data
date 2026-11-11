#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node{
	ll a;
	char c;
};
struct r{
	int spos;
	int epos;
	char c;
	long long rest;
};
// main spos!= epos
void rangecmp(r& pos,vector<node> strs,ll& ans){
	ll srest=strs[pos.spos].a,erest=strs[pos.epos].a;
//	cout<<"test:"<<pos.c<<" "<<srest<<" "<<erest<<endl;
	if(pos.c=='s'){
		srest=pos.rest;
	}else if(pos.c=='e') {
		erest=pos.rest; 
//		cout<<'e'<<endl;
	}
//	cout<<"test:"<<srest<<" "<<erest<<endl;
	if(strs[pos.spos].c!=strs[pos.epos].c){
		if(srest>erest){
			pos.c='s';
			pos.rest=srest-erest;
//			cout<<"cmp:"<<srest<<" "<<erest<<" "<<pos.rest<<" "<<endl;
			pos.epos--;
			ans += erest;
		}else if(srest<erest){
			pos.c='e';
			pos.rest=erest-srest;
//			cout<<"cmp:"<<pos.rest<<" "<<endl;
			pos.spos++;
			ans+=srest;
		}else{
			pos.spos++;pos.epos--;
			pos.c='n';
			pos.rest=0;
			ans+=srest;
			
		}
	}else{
		if(srest>erest){
			pos.c='s';
			pos.rest=strs[pos.spos].a-strs[pos.epos].a;
			pos.epos--;	
		}else if(srest<erest){
			pos.c='e';
			pos.rest=strs[pos.epos].a-strs[pos.spos].a;
			pos.spos++;
		}else{
			pos.spos++;pos.epos--;
			pos.c='n';
			pos.rest=0;
		}
	}
}


int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string s;
	int n; 
	cin>>n;
	vector<node> strs;
//	int tot=0;
	for(int i=0;i<n;i++){
		ll ai;char ci;
		cin>>ai>>ci;
		strs.push_back({ai,ci});
//		tot+=ai;
	}
	r pos={0,n-1,'n',0};
	long long ans=0;
	while(pos.spos!=pos.epos){
		int pos1=pos.spos,pos2=pos.epos;
//		cout<<pos.spos<<" "<<pos.epos<<pos.rest<<" "<<pos.c<<" "<<ans<<endl;
		rangecmp(pos,strs,ans);
		if(pos.spos==pos2&&pos.epos==pos1) {
//			cout<<"test:"<<pos1<<pos2<<endl;
			break;
		}
	}
//	cout<<pos.spos<<" "<<pos.epos<<pos.rest<<" "<<pos.c<<" "<<ans<<endl;
	cout<<ans;
	
	
	return 0;
}


