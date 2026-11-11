#include<bits/stdc++.h> 
using namespace std;
long long a[10001];
long long b[10001];
long long maxn=-1;
int andn(int x,int y){
	return x&y;
}
int cmp(int x,int y){
	return x>y;
}
int main(){
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(m==1){
		for(int i=0;i<n;i++){
			b[i]=andn(a[i],a[i]);
			maxn=max(maxn,b[i]);
		}
		cout<<maxn;
		return 0;
	}
	if(m==2){
		for(int i=0;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				b[i]=andn(a[i],a[j]);
				maxn=max(maxn,b[i]);
		    }
	    }
	    cout<<maxn;
	    return 0;
	}
	if(m==n){
		int t=a[0];
		for(int i=1;i<n;i++){
			t=a[i]&t;
		}
		cout<<t;
		return 0;
	}
	int tn=a[0];
	sort(a,a+n,cmp);
	for(int i=1;i<m;i++){
	tn=andn(tn,a[i]);
}
cout<<tn;
	return 0;
}
