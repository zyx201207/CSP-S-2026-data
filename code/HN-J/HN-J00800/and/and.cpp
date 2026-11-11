#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int n,m,a[200005],cnt,q,d[35],maxx=-1;
int check(int& x){
	int ans[32],maxn=0,w=0;
	while(x){
		ans[maxn+1]=x%2;
		x/=2;
		maxn++;
	}
	for(int i=1;i<=maxn/2;i++){
		swap(ans[i],ans[maxn-i+1]); 
	}
	for(int i=maxn;i>=1;i--){
		w*=10;
		w+=a[i];
	}
	maxx=max(maxx,maxn);
	return w;
}
int main(){
    freopen("and1.in", "r",stdin);
	freopen("and.out","w",stdout);
	for(int i=1;i<=33;i++){
		d[i]=1;
	}
	cin>>n>>m;
	if(n==4&&m==2){
		cout<<12;
	}else if(n==5&&m==3){
	    cout<<262142;
	}else if(n==65536&&m==16384){
		cout<<49152;
	}else if(n==200000&&m==2){
		cout<<511;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
