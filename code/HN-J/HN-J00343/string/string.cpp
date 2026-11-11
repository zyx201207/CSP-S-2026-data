#include <bits/stdc++.h>

#define fr for
#define int long long

inline int read(){
	int x=0,f=0;char ch=getchar();
	while(ch<'0'||ch>'9'){
		f|=ch=='-';ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return f?-x:x;
}

using namespace std;

const int N=2e5+7;
char __[5];
/*
都 2026 年了，我怎么还在考 J 组？

qwertyuiop[]\asdfghjkl;'
zxcvbnm,./`
*/
#define pic pair<int,char>
#define fi first
#define se second
struct node{
	int l, r;
	char ch;
	bool operator<(const node&rhs)const{
		return l<rhs.l;
	}
};
vector<node>s;
vector<node>d;

signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout) ;
	int n=read(),sum=0;
	fr(int i=1;i<=n;i++){
		int x=read();
		
		scanf("%s",__);
		s.push_back({sum+1,sum+x,__[0]});
//		a[i]=x;
		sum+=x;
//		fr(int j=0;j<26;j++){
//			pre[i][j]=pre[i-1][j]+((__[0]-'a'==j)*(x));
//		}
	}
	sort(s.begin(),s.end());
	int mid=(sum+1)/2;
//	fr(auto _:s){
//		int l=_.l,r=_.r;char ch=_.ch;
//		if(r<=mid)d.push_back({l,r,ch});
//		else if(l>mid)continue;
//		else d.push({l,mid,ch});
//	}

	vector<node>l,r;
	fr(auto _:s){
		int _l=_.l,_r=_.r;char ch=_.ch;
		if(sum&1){
			if(_l<mid&&_r<mid)l.push_back(_);
			else if(_l>mid&&_r>mid)r.push_back(_);
			else {
				if(_l!=mid){
					l.push_back({_l,mid-1,ch});
				}
				if(_r!=mid)r.push_back({mid+1,_r,ch});
			}
		}
		else{
			if(_l<=mid&&_r<=mid)l.push_back(_);
			else if(_l>mid&&_r>mid)r.push_back(_);
			else {

					l.push_back({_l,mid,ch});
				
				r.push_back({mid+1,_r,ch});
			}
		}
	}
	sort(l.begin(),l.end());
	sort(r.begin(),r.end());
//	fr(auto x:l){
//		cerr<<x.l<<' '<<x.r<<' '<<x.ch<<'\n';
//	}
//	cerr<<"R\n";
//	fr(auto x:r){
//		cerr<<x.l<<' '<<x.r<<' '<<x.ch<<'\n';
//	}
	int ans=0;
	fr(int i=0;i<l.size();i++){
		int ql=sum-l[i].l+1,qr=sum-l[i].r+1;
//		cerr<<ql<<' '<<qr<<'\n';
		if(ql>qr)swap(ql,qr);
		while(r.size()&&ql<=r.back().l&&r.back().r<=qr){
			if(l[i].ch!=r.back().ch)ans+=r.back().r-r.back().l+1;
			r.pop_back();
		}
		if(r.empty())continue;
		if(r.back().r>=ql){
			if(l[i].ch!=r.back().ch)ans+=r.back().r-ql+1;
			r.back().r=ql-1;
		}
	}
	cout<<ans;
//
//	fr(auto _:l){
//		int _l=_.l,_r=_.r;char ch=_.ch;
//		int sm=0;
//		int nl=(sum-_l+1),nr=sum-_r+1;
//		while(ptr>=0&&r[ptr].l>nr)ptr--;
//		while(ptr>=0&&)
//	}
	return 0;
}
/*
2
2 a
3 a

6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/
