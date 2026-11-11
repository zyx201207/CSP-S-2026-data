#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
const int M=3e5+5;
int n,m,a[N],b[M],c[M];
void solve1(){
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(b[a[j]]){
				for(int k=b[a[j]]+1;k<j;k++) b[a[k]]=0;
			}
			b[a[j]]=j;
		}
		for(int j=1;j<=m;j++){
			if(b[j]) c[j]++;
			b[j]=0;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
}
void solve2(){
	for(int i=1;i<=m;i++){
		int cnt=0;
		for(int j=1;j<=n;j++){
			if(a[j]==i||a[n]==i) cnt++;
		}
		cout<<cnt<<" ";
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=5000&&m<=3000) solve1();
	else if(n<=2e5){
		if(m<=2) solve2();
	}
	return 0;
}
