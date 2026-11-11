#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5,M=3e5+5; 
//n log n?
//but I have n^2 ???
#ifdef __linux__
#define gc getchar_unlocked
#define pc putchar_unlocked
#else
#define gc _getchar_nolock
#define pc _putchar_nolock
#endif
namespace IO{
	bool rd(int &x){
		char c=gc();
		bool f=0;
		while(!isdigit(c)){
			f=f|(c=='-');
			if(c==EOF)return 0;
			c=gc(); 
		}
		x=0;
		while(isdigit(c)){
			x=(x<<3)+(x<<1)+(c^48);
			c=gc();
		}
		return 1;
	}
	template<typename T,typename ...U> bool rd(T &x,U &...y){
		if(!rd(x))return 0;
		return rd(y...);
	}
	void wt(int x){
		string s="";
		do{
			s+=x%10^48;
			x/=10;
		}while(x);
		for(int i=s.size()-1;~i;i--)
			pc(s[i]);
	}
	void wt(char c){pc(c);}
	void wt(string s){for(char c:s)pc(c);}
	void wt(const char* s){while(*s)pc(*s++);}
	template<typename T,typename ...U> void wt(T x,U ...y){wt(x);wt(y...);}
}using namespace IO;
int n,m;
int a[N],pos[N];
map<int,int> last;
int cnt[N];
signed main(){
	freopen("card.in" ,"r",stdin );
	freopen("card.out","w",stdout);
//	scanf("%lld%lld",&n,&m);
	rd(n,m);
	for(int i=1;i<=n;i++){
//		scanf("%lld",&a[i]);
		rd(a[i]);
		pos[last[a[i]]]=i;
		last[a[i]]=i;
	}
	for(int game=1;game<=n;game++){
		for(int i=game;i<=n;){
			if(pos[i]!=0){
				i=pos[i];
				continue;
			}
			if(a[i]<=m)
				cnt[a[i]]++;
			i++;
		}
	}
	for(int i=1;i<m;i++)
		wt(cnt[i],' ');
	wt(cnt[m]);
	return 0;
}

