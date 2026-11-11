#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,k;
int w[1000000];
int a[1000000],t[1000000];
int x[1000000],y[1000000];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
    	cin>>w[i];
	}for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[j]>>t[j];
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x[i]>>y[i];
	}
	for(int i=1;i<=q;i++){
		cout<<w[x[i]]+w[y[i]]+t[x[i]]+t[y[i]]<<endl;
	}
	return 0;
}
