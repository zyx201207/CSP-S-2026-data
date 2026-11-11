#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],MAX=-1e9,m;
void js(long long x,long long nest,long long cs){
	if(cs==m){
		MAX=max(MAX,x);
		return ;
	}
	for(long long i=nest+1;i<=n;i++){
		if(x==0){
			x=a[i];
			js(x,i,cs+1);
		}
		js(x&a[i],i,cs+1);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		MAX=max(MAX,a[i]);
	}
	if(m==1){
		cout<<MAX;
		return 0;
	}
	if(n<=20){
		MAX=-1e9;
		js(0,0,0);
		cout<<MAX;
		return 0;
	}
	if(m==n){
		MAX=a[1];
		for(long long i=2;i<=n;i++){
			MAX=MAX&a[i];
		}
		cout<<MAX;
		return 0;
	}
	if(m==2){
		MAX=-1e9;
		for(long long i=1;i<=n;i++){
			for(long long j=i+1;j<=n;j++){
				long long tmp=a[i]&a[j];
				if(MAX<tmp){
					MAX=tmp;
				}
			}
		}
		cout<<MAX;
		return 0;
	}
	if(m==n-1){
		MAX=a[1];
		for(long long i=2;i<n;i++){
			MAX=MAX&a[i];
		}
		long long k=MAX;
		MAX=0;
		for(long long i=1;i<=n;i++){
			long long tmp=k;
			tmp=tmp&a[i];
			MAX=max(MAX,tmp);
		}
		cout<<MAX;
		return 0;
	}
	MAX=-1e9;
	js(0,0,0);
	cout<<MAX;
	return 0;
}
