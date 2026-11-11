#include<bits/stdc++.h>

using namespace std;

const int N=500010;

struct ac{
	int w;
	int v;
};


long long n,m;
long long b[N];
long long c[N];
ac ans[N];
int f=1;
long long q[1000100]; 

bool cmp(int x,int y){
	return x<y;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	int cnt=0;
	for(int i=1;i<=n;i++){
		cin >> b[i];
		q[b[i]]+=1;
		if(q[b[i]]>cnt){
			cnt=q[b[i]];
		}
	}
	sort(b+1,b+n+1,cmp);
	c[1]=b[1];
	bool g=1;
	int yy=0;
	for(int i=2;i<=n;i++){
		c[i]=b[i]-b[i-1];
		if(i>=3 && c[i] !=c[i-1]){
			g=0;
		}
		if(i>=3){
			yy=c[i];
		}
	}
	int ggg=0;
	if(g==1){
		while(m>0){
			m-=yy;
			yy*=2;
			ggg++;
		}
		if(cnt=0){
			cout << ggg+1;
		}
		else{
			cout << ggg+cnt;
		}
		return 0;
	}
	ans[1].w=0;
	ans[1].v=1;
	for(int i=2;i<=n;i++){
		if(ans[i-1].w+(i-1)*c[i]>m){
			ans[i].w=0;
			ans[i].v=1;
		}
		else{
			ans[i].w=(i-1)*c[i]+ans[i-1].w;
			ans[i].v=ans[i-1].v+1;
		}
	}
	int ql=0;
	for(int i=1;i<=n;i++){
		if(ans[i].v>ql){
			ql=ans[i].v;
		}
	}
	if(ql==0){
		cout << cnt;
	}
	else{
		cout << ql;
	}
	return 0;
} 
