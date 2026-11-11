#include<bits/stdc++.h>

using namespace std;

#define int long long
//y0,y1 nope
//Oct31==Dec25?
//3:52 T2
//freopen("
//play.petalwar.top awa
//could i get 300 points?
//maybe?
/*
lol :)
x x xxx
o o ooo
Bruh why T3 so hard
5:55实在是骗不了一点了Bruh
getchar_unlocked应该没有问题吧
998244353
Im -lyy-
luogu:lyy0918lyy 
*/

int x[2000006];
int dp[2000006];
int f[2000006];

int c,t;

//#define getchar _getchar_nolock
#define getchar getchar_unlocked

int read(){
	char gc=getchar();
	int ans=0;
	bool g=0;
	if(gc=='-'){
		g=true;
		gc=getchar();
	}
	while('0'<=gc&&gc<='9'){
		ans*=10;
		ans+=(gc^48);
		gc=getchar();
	}
	return (g?-ans:ans);
}

vector<int> w;

void _main(){
	memset(f,0x3f,sizeof(f));
	memset(dp,0,sizeof(dp));
	
	int n,d;
	n=read();d=read();
	for(int i=1;i<=n;i++){
		x[i]=read();
	}
	
	if(c==11||c==12){
		int v=x[2]-x[1];
		if(d<v*2){
			cout<<0<<endl;
		}else{
			cout<<max(n-2*(d/v)+1,0ll)<<endl;
		}
		return;
	}
	
	int ans=0;
	
	for(int u=n-1;u>=1;u--){
		w.clear();
		memset(f,0x3f,sizeof(f));
		memset(dp,0,sizeof(dp));
		
		f[u]=0;
		dp[u]=1;
		
		w.push_back(u);
		
//		for(int i=1;i<u;i++)cout<<"---,--- ";
		
		int j=0;
		
		for(int i=u+1;i<=n;i++){
			while(w.size()&&x[w.front()]+d<x[i])w.erase(w.begin());
			if(w.size()){
				f[i]=f[w.front()]+1;
				dp[i]=0;
				j=0;
				while(j<w.size()&&f[w[j]]==f[w.front()]){
					//cout<<w[j]<<" "<<dp[w[j]]<<" ";
					dp[i]+=dp[w[j]];
					j++;
				}
				//cout<<endl;
			}
			//cout<<"-";
			while(w.size()&&f[w.back()]>f[i]){
				//cout<<"pp"<<w.back()<<endl;
				w.pop_back();
			}
			w.push_back(i);
			if(dp[i]==2){
			ans++;
			}
		}
		//cout<<"/"<<endl;
	}
	
	cout<<ans<<endl;
	
	return;
}

signed main(){

	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read();t=read();
	
	while(t--){
		_main();
	}

	return 0;
}

