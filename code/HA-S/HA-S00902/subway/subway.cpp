#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
ull c,n,m,d,q,tmp,t,ret[500005][505],x,y,ans=0,ty=0,tans;
vector<int> tim(1);
bitset<500005> l[505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	srand(time(0));
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<m;i++){
		cin>>tmp;
		tim.push_back(tmp);
	}
	for(int i=0;i<n;i++){
		cin>>tmp;
		for(int j=0;j<tmp*2;j++){
			cin>>t;
			if(j&1)ret[j][i]=t;
			else l[i][t]=true;
		}
	}
	cin>>x>>y;
	while(true){
		ull nw=x,ch=y;
		while(nw!=y){
			tans=0;
			if(ty>10000000){
				cout<<ans;
				return 0;
			}
			ull tt=0;
			bitset<500005> ex;ex=l[nw]&l[ch];
			if(ex.any()){
				for(tt=0;ex[tt];tt++);
				tans+=tim[tt]+ret[ch][tt];
			}
			ty++;
			nw=ch;
			ch=rand()%m;
		}
		ans=min(ans,tans);
	}
	
	
}