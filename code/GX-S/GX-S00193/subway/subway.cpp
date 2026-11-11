#include<bits/stdc++.h>
using namespace std;
struct sj{
	int a[10000000][100000000],t[1000000000][100000000];
}l1[100000005];
int main{
freopen("subway.in",'r',stdin);
freopen("subway.out",'w',stdout);
	long long c,n.m.d.q;
	cin>>c>>n>>m>>d>>q;
	long long w[10000000005];
	for(int i=0;i<m;i++){
		cin>>w[i];
	}
	long long k[5000000005]
	for(int i=0;i<n;i++){
		cin>>k[i];
		for(int j=0;j<k[i];j++){
			cin>>l1[i].a>>l1[i].t;
		}
	}
	long long r[1000000000],h[1000000000];
	for(int i=0;i<n;i++){
	    cin>>r[i]>>h[i];
	}
	
	int sum=0;
	for(int i=0;i<n;i++){
		if(r[i]==h[i]){
			cout<<sum;
		}else if(r[i]<h[i]){
			sum+=w[r[i]];
			sum+=t[i][r[i]];
			if(r[i+1]==a[i][i+1]){
				sum+=t[i][r[i+1]];
			}else{
				sum+=t[i+1][r[i]];
			}
		}else if(r[i]>h[i]){
			sum+=w[r[i]];
			sum+=t[i][r[i]];
			if(r[i-1]==a[i][i-1]){
				sum+=t[i][r[i-1]];
			}else{
				sum+=t[i+1][r[i-1]];
			}
		}
	    cout<<sum<<endl;
	}
    return 0;
}
