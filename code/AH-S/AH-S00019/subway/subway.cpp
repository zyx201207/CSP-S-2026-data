#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,k[5005],w[500005],a[5005][5005],t[5005][5005],x[5005],y[5005];
int f(int xx){
	for(long long i=1;i<=n;i++){
		for(long long j=1;j<=k[i];j++){
			if(a[i][j]==xx){
				return t[i][j];
			}
		}
	}
}
int timemin(int ax,int ay){
	int axx=ax;
	int ayy=ay;
	return f(axx)+f(ayy);
}

int main(){
	//freopen("subway.in", "r", stdin);
	//freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
    	cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x[i]>>y[i];
	}
	for(int i=1;i<=q;i++){
	    int sum=w[x[i]]+w[y[i]];
	    sum+=timemin(x[i],y[i]);
	    cout<<sum<<endl;
    }
	return 0;
}

