#include <bits/stdc++.h>
using namespace std;

const int N=2e5+5;

int n,m;
long long a[N];
int ans;

void Init(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
}

int solve(int t,int i,int num){
	if(num==m){
		return a[i];
	}
	for(int j=i+1;j<n;j++){
		ans=max(ans,t&solve(a[j],j,num+1));
	}
}

void Printf(){
	cout<<ans;
}

int main(){
	Init();
	solve(a[0],0,0);
	Printf();
	return 0;
}
//¼ÇµÃÉ¾×¢ÊÍ 
