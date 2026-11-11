#include<bits/stdc++.h>
using namespace std;
int const N=5e5+10,M=3e5+10;;
int a[N];
int st[M];
int cnt[M];
int n,m;

void solve1(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)st[j]=-1;
		
		for(int j=i;j<=n;j++){
			if(st[a[j]]>0){
				for(int k=st[a[j]];k<=j;k++){
					st[a[k]]=0;
				}
			}
			st[a[j]]=j;
		}
		for(int j=1;j<=m;j++){
			if(st[j]>0)cnt[j]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
}

void solve2(){
	for(int i=1;i<=n;i++){
		cnt[a[i]]=i;
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
}

void solve3(){
	for(int i=1;i<=n;i++){
		cnt[a[i]]++;
		if(a[i]!=a[n])cnt[a[n]]++;
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
}

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	int flag=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i-1]>a[i])flag=1;
	}
	if(m<=2)solve3();
	else if(!flag)solve2();
	else solve1();
	return 0;
} 
