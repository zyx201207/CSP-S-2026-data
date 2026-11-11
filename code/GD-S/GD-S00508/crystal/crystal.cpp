#include<bits/stdc++.h>
using namespace std;

int n,ans=0;
long long m;
int a[200020];
int aa[100010];
int cost,cur,cnt;

void add(int st){
	int l=st-1;
	while(true){
		if(a[l]==0)l--;
		else{
			break;
		}
		if(l<=0){
			return;
		}
	}
	int derta=cost-l;
	for(int i=1;i<=a[l];++i){
		m-=derta;
		if(m<0){
			return;
		}
		else{
			ans++;
		}
	}
	if(m==0){
		return;
	}
	else{
		add(l);
	}
}

int check(int st){
	int r=st+1;
	while(true){
		if(a[r]==0)r++;
		else{
			break;
		}
		if(r>n){
			return 1;
		}
	}
	int derta=(r-cost)*cost;
	for(int i=1;i<=a[r];++i){
		m-=derta;
		if(m<0){
			return 1;
		}
		else{
			ans++;
		}
	}
	cost=r+100000;
	return 0;
}

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    int x,st;
    cur=m;
    for(int i=1;i<=n;++i){
    	int u;
        cin>>u;
        aa[i]=u;
        a[u+100000]++;
        if(a[u+100000]>=ans){
        	ans=a[u+100000];
        	x=u+100000;
		}
    }
    sort(aa+1,aa+n+1);
	if(ans==a[aa[n/2+1]+100000]){
		st=aa[n/2+1]+100000;
	}
	else{
		st=x;
	}
	cost=st;
	add(st);
	while(true){
		if(check(st)){			
			cout<<ans<<'\n';
			return 0;
		}
		else{
			m=cur;
			add(cost);
		}
	}
}
