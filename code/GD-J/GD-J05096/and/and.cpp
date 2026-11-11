#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,maxn,maxlen;
ll a[200001],b[200001];
string s[200001];
int fun(int n,int i){
	int x=0;
	while(n){
		if(n%2==1){
			s[i][x]='1';
		}
		x++;
	}
	if(maxlen<x){
		maxlen=x;
	}
}
void and1(int n){
	int sum=0,x=maxlen;
	for(int i=1;i<=n;i++){
		if(sum==m){
			return;
		}
		if(s[i][x]!='1'){
			b[i]++;
			sum++;
		}
		x--;
	}
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.in","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}
	if(m==1){
		cout<<maxn;
		return 0;
	}
	else if(m==2){
		maxn=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(i==j){
					continue;
				}
				maxn=max(maxn,a[i]&a[j]);
			}
		}
		cout<<maxn;
	}
	else if(m==n){
		int x=a[1]&a[2];
		for(int i=3;i<=n;i++){
			x=x&a[i];
		}
		cout<<x;
	}
	else{
		bool q=0;
		sort(a+1,a+1+n);
		for(int i=1;i<=n;i++){
			fun(a[i],i);
		}
		and1(n);
		for(int i=1;i<=n;i++){
			if(!b[i]){
				continue;
			}
			if(q==0){
				maxn=a[i];
				q=1;
			}
			else{
				maxn=maxn&a[i];
			}
		}
		cout<<maxn;
	}
	return 0;
}
