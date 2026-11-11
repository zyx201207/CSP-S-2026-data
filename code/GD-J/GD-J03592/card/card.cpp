#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+10;
int a[N];
int tt[N];
bool myf=0;
int n,m;
void solve(){
	
}
void solve1(){
	int sum[N];
	sum[0]=0;
	for(int i=1;i<=m;i++){
		sum[i]=tt[i]+sum[i-1];
		cout<<sum[i]<<" ";
	}
	
}
bool t2[N];
void solve2(){
	stack<int> pq;
	int sum[N];
	memset(sum,0,sizeof sum);
	for(int p=1;p<=n;p++){
		for(int i=p;i<=n;i++){
			pq.push(a[i]);
			if(t2[a[i]]==0){
				t2[a[i]]=1;
			}else{
				pq.pop();
				while(pq.top()!=a[i]){
					t2[pq.top()]=0;
					pq.pop();
				}
			}
			
		}
		while(!pq.empty()){
			sum[pq.top()]++;
			pq.pop();
		}
	
		memset(t2,0,sizeof t2);
	}
	for(int i=1;i<=m;i++){
		cout<<sum[i]<<" ";
	}

}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<a[i-1]){
			myf=1;
		}
		tt[a[i]]++;
	}
	if(myf==0){
		solve1();
	}else if(1==1){
		solve2();
	}
	solve();
	return 0;

}
