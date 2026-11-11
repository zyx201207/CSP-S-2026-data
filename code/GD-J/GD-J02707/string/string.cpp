#include<bits/stdc++.h>
using namespace std;
#define int long long
struct st{int a;char c;};
deque<st>d;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,ans=0,ansr=0;cin>>n;//cerr<<n<<' ';
	char lstc=0;
	for(int i=1;i<=n;++i){
		int _a;char _c;cin>>_a>>_c;
		if(d.size()==0||lstc!=_c){
			d.push_back({_a,_c});
			rd.push_front({_a,_c});
		}
		else{
			d.back().a+=_a;
			rd.front().a+=_a;
		}
		lstc=_c;
	}
	/*
	while(d.size()){
		cerr<<d.front().a<<d.front().c<<"\n";
		d.pop_front();
	}
	*/
	while(d.size()){
		st fr=d.front(),bk=d.back();
		//cerr<<fr.a<<"--"<<fr.c<<" "<<bk.a<<"--"<<bk.c<<" "<<ans<<"--";
		if(fr.c!=bk.c){
			if(fr.a==bk.a){//cerr<<"a";
				ans+=fr.a;
				if(d.size())d.pop_front();
				if(d.size())d.pop_back();
			}else if(fr.a>bk.a){//cerr<<"b";
				ans+=bk.a;
				d.front().a-=d.back().a;
				if(d.size())d.pop_back();
			}else{//cerr<<"c";
				ans+=fr.a;
				d.back().a-=d.front().a;
				if(d.size())d.pop_front();
			}
		}
		else{
			if(fr.a==bk.a){//cerr<<"d";
				if(d.size())d.pop_front();
				if(d.size())d.pop_back();
			}else if(fr.a>bk.a){//cerr<<"e";
				d.front().a-=d.back().a;
				if(d.size())d.pop_back();
			}else{//cerr<<"f";
				d.back().a-=d.front().a;
				if(d.size())d.pop_front();
			}
		}//cerr<<ans<<"\n";
	}
	cout<<ans;
	//cerr<<'\n'<<ans;
	return 0;
}
