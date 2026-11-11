#include <bits/stdc++.h>
using namespace std;
const int N=1e6+3;
long long a[N];
set<long long>as;
int n,m;
long long b[N];
long long c[N];
long long d[N];
long long e[N];
long long f[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=n;i>=1;i--){
		int yu=as.size();
		as.insert(a[i]);
		if(yu==as.size()&&b[a[i]]!=0){
			c[i]=b[a[i]]-i;
		}
		else{
			f[a[i]]=i;
			b[a[i]]=i;
		}
	}
	for(int i=1;i<=n;i++){
		if(c[i]!=0){
			for(int j=i;j<=i-1+c[i];j++){
				b[a[j]]=0;
			}
			i=i-1+c[i];
		}
		else{
			b[a[i]]=1;
		}
	}
	for(int v=1;v<=m;v++){
		if(b[v]==1){
			e[v]+=1;
		}
	}
	for(int i=2;i<=n;i++){
		b[i-1]=0;
		if(c[i]!=0){
			for(int j=i;j<=i-1+c[i];j++){
				b[a[j]]=0;
			}
			i=i-1+c[i];
		}
		else{
			b[a[i]]=1;
		}
		for(int v=1;v<=m;v++){
		 if(b[v]==1){
			e[v]+=1;
		 }
	    }
	}
	for(int i=1;i<=m;i++){
		cout<<e[i]<<" ";
	}
	/*
	for(int i=1;i<=n;i++){
		cout<<c[i]<<" ";
	}
	cout<<endl;
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	*/
	return 0;
}
