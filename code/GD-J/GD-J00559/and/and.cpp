#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long a[N];
long long popcount(long long a){
	long long ans=0;
	while(a){
		if(a&1)	ans++;
		a>>=1;
	}
	return ans;
}
int len[N];
bool cmp(long long x,long long y){
	if(popcount(x)!=popcount(y))	return popcount(x)>popcount(y);
	return x>y;
}
bool cmp1(long long x,long long y){
	return x>y;
}
int n,m;
long long maxx=-1;
long long allll;
bool tpB(){
	for(int i=1;i<=n;i++){
		if(a[i]!=i-1)	return 0;
	}
	return 1;
}
long long dfsmax;
long long dfsa[N];
bool vis[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	
	for(int i=1;i<=n;i++){
		len[i]=log2(a[i])+1;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxx=max(maxx,a[i]);
	}
	
	if(m==1){
		cout<<maxx;
		return 0;	
	}
	if(m==n){
		allll=a[1];
		for(int i=2;i<=n;i++)	allll&=a[i];
		cout<<allll;
		return 0;
	}
	if(n<=1e4&&m==2){
		long long maxand=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(i!=j){
					long long y=a[i]&a[j];
					maxand=max(maxand,y);
				}
			}
		}
		cout<<maxand;
		return 0;
	}
	if(n<=20){
		long long sum;
		for(int i=n;i>=n-m+1;i--)	vis[i]=1;
		do{
				for(int i=1;i<=n;i++){
					if(vis[i]){
						sum=a[i];
						break;
					}
				}
				for(int i=1;i<=n;i++){
					if(vis[i]){
						sum&=a[i];
					}
//					cout<<vis[i]<<" ";
				}
				dfsmax=max(dfsmax,sum);
//			for(int i=1;i<=n;i++){
//				cout<<vis[i]<<" ";
//			}
//			cout<<endl;
		}while(next_permutation(vis+1,vis+n+1));
		cout<<dfsmax;
		return 0;
	}
	if(tpB()){
		sort(a+1,a+n+1,cmp1);
		long long tot=a[1];
		for(int i=2;i<=n;i++){
			tot&=a[i];
			if(m==i)	break;
		}
		cout<<tot;
		return 0;
	}
	sort(a+1,a+n+1,cmp);
	long long tot=a[1];
	for(int i=2;i<=n;i++){
		tot&=a[i];
		if(m==i)	break;
	}
	cout<<tot;
	return 0;
}
