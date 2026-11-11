#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
typedef pair<long long,long long> pr;

const int N=500,M=509,R=100009;

ll c,n,m,d,q,w[M],k,at,tt,rx[R],ry[R],ds[M],ks[N];
ll a[N][500],t[N][500];
ll sta[M][22],stat[M][22];



ll bfs(ll x,ll y){
	priority_queue<pr,vector<pr>> Q;
	bool epm[M],epn[N];
	memset(epm,0,sizeof(epm));
	memset(epn,0,sizeof(epn));
	Q.push(make_pair(0,x));
	while(!Q.empty()){
		pr cur=Q.top();
		Q.pop();
		ll dis=-cur.first;
		ll pos=cur.second;
		
		//cout<<dis<<"/"<<pos<<"/"<<"\n";
			
		
		if(pos==y) return dis;
		epm[pos]=1;
		for(int i=0;i<ds[pos];i++){
			
			ll line=sta[pos][i];
			ll t1=stat[pos][i];
			//cout<<ks[line]<<'$';
			//if(epn[line]){cout<<'p'<<"\n";continue;}
			
			epn[line]=1;
			for(int j=0;j<ks[line];j++){
				ll to=a[line][j];
				ll t2=t[line][j];
				//cout<<to<<"@"<<t1<<'!'<<t2<<"\n";
				if(!epm[to]) Q.push(make_pair(-dis-(t1+t2),to));
			}
		}
	}
}


int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<m;i++){
	cin>>w[i];
	}
	for(int i=0;i<n;i++){
		cin>>k;
		ks[i]=k;
		for(int j=0;j<k;j++){
			cin>>at>>tt;
			a[i][j]=at;
			t[i][j]=tt;
			sta[at][ds[at]]=i;
			stat[at][ds[at]]=tt;
			ds[at]++;
		}
	}
	for(int i=0;i<q;i++){
		cin>>rx[i]>>ry[i];
	}
	
	if(c<11){
		for(int i=0;i<q;i++){
		cout<<bfs(rx[i],ry[i])+w[rx[i]-1]+w[ry[i]-1]<<"\n";
		}
	}
}
