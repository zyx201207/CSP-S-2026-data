#include<bits/stdc++.h>
using namespace std;
const int N=500005;
const long long MAXN=1000000000007;
long long n,m,len=0;
long long G[N],true_[N];   
long long val[N];
vector<int> G2[N];
int k;
struct graph{
	long long d1[5005];
	long long maxt;
}d[5005];

struct l{
	long long t;
	long long v;
}G1[N];

struct ll{
	long long tt;
	long long vv;
	long long f;
}da[N];

struct lll{
	long long vvv;
	long long num;
}da2[N];
int cmp(ll x,ll y){
	if(x.vv==y.vv){
		return x.tt>y.tt;
	}
	else{
		return x.vv<y.vv;
	}
}

void get(){
	for(int i=1;i<=n;i++){
		val[i]=1;
	}
	for(int i=2;i<=n;i++){
		if(G[i]==G[i-1])val[i]+=1;
	}
	for(int i=1;i<=n;i++){
		if(val[i]==1){
			len++;
			G1[len].v=G[i];
			G1[len].t=val[i];
			da[len].tt=val[i];
			da[len].f=i;
		}
		else{
			continue;
		}
	}
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>G[i];
	}
	sort(G+1,G+n+1);
	get();
	
	for(int i=1;i<len;i++){
		for(int j=i+1;j<=len;j++){
			G2[i].push_back(j);
			d[j].d1[i]=abs(G1[i].v-G1[j].v);
			da[j].vv+=abs(G1[i].v-G1[j].v);
			da2[j].vvv=da[j].vv;
			da2[j].num=da[j].f;
			da[i].vv+=abs(G1[i].v-G1[j].v);
			da2[i].vvv=da[i].vv;
		}
	}
	sort(da+1,da+len+1,cmp);
	
	int k;
	
	for(int i=1;i<=len;i++){
		if((da[1].vv==da2[i].vvv)&&(da[1].f==da2[i].num)){
			k=i;
		}
	}
	for(int i=1;i<=k-1;i++){
		true_[i]+=(G1[k].v-G1[i].v);
	}
	sort(true_+1,true_+k);
	int ans=0,cnt=1;
	while(m-true_[cnt]>=0&&cnt<=k-1){
		m=m-true_[cnt];
		ans++;
		cnt++;
	}
	ans+=G1[k].t;
	cout<<ans;
	return 0;
}
