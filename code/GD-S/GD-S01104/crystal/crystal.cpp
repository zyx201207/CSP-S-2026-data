#include<iostream>
#include<stdio.h>
#include<queue>
#include<vector>
#include<algorithm>
#define LL long long
#define MINM -1e12-5
#define MAXM 1e12+5
using namespace std;

LL n,m;
LL ans=0,anspop=0,maxi=MINM,mini=MAXM;
LL sum=0;
LL a[500005];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	queue<LL> q;
	LL sum=0;
	LL last=a[1];
	LL cost=0;
	for(int i=1;i<=n;i++){
		if(last==a[i]){
			sum++;
			q.push(i);
		}else{
			cost+=sum*(a[i]-last);
			last=a[i];
			sum++;
			q.push(i);
			while(!q.empty()&&cost>m){
				LL now=q.front();
				q.pop();
				sum--;
				cost-=(last-a[now]);
			}
		}
		ans=max(ans,sum);
	}
	printf("%lld",ans);
	
	return 0;
} 
