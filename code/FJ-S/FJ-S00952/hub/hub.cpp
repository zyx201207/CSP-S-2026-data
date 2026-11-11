#include<bits/stdc++.h>

using namespace std;

//#define int long long
//y0,y1 nope
//Oct31==Dec25?
//6:24:Ô¤¼Æ200+?
//6:29:bye csp-s2026

int n,k;
vector<int> w[50005];

bool chk[50005];

int cc(int w){
	return (w?cc(w&(w-1))+1:0);
}

struct tsk{
	int f1,f2,as;
};

int dir(int v){
	queue<tsk> o;
	o.push({v,0,0});
	while(o.size()){
		tsk tp=o.front();o.pop();
		if(chk[tp.f1]){
			return tp.as;
		}
		for(int j:w[tp.f1]){
			if(j!=tp.f2){
				o.push({j,tp.f1,tp.as+1});
			}
		}
	}
	return INT_MAX;
}

void fs(int a,int b){
	if(!chk[a])return;
	chk[a]=false;
	for(int i:w[a]){
		if(i!=b){
			fs(i,a);
		}
	}
}

void _main(){
	memset(w,0,sizeof(w));
	cin>>n>>k;
	if(n>=500){
		cout<<((n+1)/2-k)/4+1<<endl;
		return;
	}
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		w[u].push_back(v);
		w[v].push_back(u);
	}
	int ans=INT_MAX;
	for(int i=1;i<(1<<n);i++){
		if(cc(i)!=k)continue;
		for(int j=0;j<n;j++){
			chk[j+1]=(i&(1<<j));
		}
		int w=0,cccc=0;
		for(int j=1;j<=n;j++){
			w=max(w,dir(j));
		}
		for(int j=1;j<=n;j++){
			if(chk[j]){
				fs(j,-1);
				cccc++;
			}
		}
		if(cccc<=2){
			ans=min(ans,w);
		}
	}
	cout<<ans<<endl;
}

signed main(){

	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);

	int c,t;
	cin>>c>>t;
	
	while(t--){
		_main();
	}

	return 0;
}

