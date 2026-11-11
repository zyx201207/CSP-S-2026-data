#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long n,m,Max=-1,pre[N],preZ[N];
long long a[N];
long long ji(long long yu){
	priority_queue<long long,vector<int>,greater<long long> >pq;
	for(int i=1;i<=n;i++){
		if(yu>=a[i])pq.push(abs(a[i]-yu));
		else break;
	}
	int km=m,ok=0;
	while(!pq.empty()&&km){
		int op=pq.top();
		pq.pop();
		if(op<=km){
			km-=op;
			ok++;
		}
		else break;
	}
	return ok;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	if(n>5000){
		for(int i=1;i<=n;i++){
			if(a[i]<0){
				pre[i]=pre[i-1]+abs(a[i]);
				preZ[i]=preZ[i-1];
			}
			else{
				pre[i]=pre[i-1];
				preZ[i]=preZ[i-1]+a[i]; 
			}
		}
		long long l=1,r=1;
		while(l<=n){
			while(r<=n){
				int needm=pre[r]-pre[l-1]+(r-l+1)*a[r]-preZ[r]+preZ[l-1];
				if(needm>m)break;
				else r++;
			}
			Max=max(Max,r-l);
			l++;
		}
	}
	else{
		for(int i=1;i<=n;i++){
			Max=max(Max,ji(a[i]));
		}
	}
	cout<<Max<<"\n";
	return 0;
} 
