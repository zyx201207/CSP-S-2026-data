#include<bits/stdc++.h>
using namespace std;

int n,m;
long long int w,maxt=INT_MIN;
long long int a[200010],maxa=INT_MIN;

queue<int> q,cnt,num;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		maxt=max(maxt,a[i]);
		if(i==1)w=a[i];
		else w=w&a[i];
	}
	if(m==1){
		cout<<maxt;
		return 0;
	}else if(m==n){
		cout<<w;
		return 0;
	}else if(m==n-1){
		long long int x,maxx;
		for(int i=1;i<=n;i++){
			x=INT_MAX,maxx=INT_MIN;
			for(int j=1;j<=n;j++)if(i!=j)x=x&a[j];
			maxx=max(maxx,x);
		}
		printf("%lld",maxx);
		return 0;
	}
	for(int i=1;i<=n-m+1;i++){
		q.push(a[i]);
		cnt.push(1);
		num.push(i);
		while(!q.empty()){
			long long int f=q.front();
			int cnt1=cnt.front(),num1=num.front();
			q.pop(),cnt.pop(),num.pop();
			if(cnt1==m){
				maxa=max(maxa,f);
				continue;
			}
			for(int j=num1+1;j<=n-m+cnt1+1;j++){
				long long int x=f&a[j];
				q.push(x),cnt.push(cnt1+1),num.push(j);
			}
		}
	}
	printf("%lld",maxa);
	return 0;
}
