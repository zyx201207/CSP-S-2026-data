#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n;
long long m;
long long a[500005];
long long sum[500005];
long long r;
int ans;
long long maxx;
long long s;
int num;
int q;
void dfs(int x){
	long long res=1;
	for(int i=x+1;i<=n;i++){
		if(sum[i]*(i-x)>ans){
			maxx=max(maxx,res);
			return ;
		}
		res++;
		ans-=sum[i]*(i-x);

	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//freopen("crystal.in","r",stdin);
	//freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==i){
			num++;
		}
	}
	if(num==n){
		m*=2;
		q=sqrt(m);
		if(q*q+q<=m){
			cout<<q+1;
		}
		else{
			cout<<q;
		}
		return 0;
	}
	sort(a+1,a+n+1);
	num=0;
	if(a[1]<0){
		s=a[1];
		for(int i=1;i<=n;i++){
			a[i]-=s;
		}
	}	
	for(int i=1;i<=n;i++){
		sum[i]=a[i]-a[i-1];
	}
	for(int i=1;i<=n;i++){
		ans=m;
		dfs(i);
    }
	cout<<maxx;
	return 0;
}

