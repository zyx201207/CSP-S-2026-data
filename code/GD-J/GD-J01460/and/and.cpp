#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;
int n,m;
int a[N];
int tn[35];
bool bt[35];
int mxt;
int tx,ty;
int ans;
int power(int x,int y){
	int sum=1;
	for(int i=1;i<=y;i++){
		sum*=x;
	}
	return sum;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		for(int j=a[i];j!=0;j-=j&(-j)) tn[(int)log2(j&(-j))]++;
	}
	for(int i=0;i<=31;i++){
		bt[i]=(tn[i]>=m);
		if(bt[i]) mxt=i;
	}
	sort(a+1,a+n+1,[](const int& x,const int& y){
		for(int i=mxt;i>=0;i--){
			tx=x&(int)power(2,i),ty=y&(int)power(2,i);
			if(tx!=ty&&bt[i]) return tx>ty; 
		}
		return x>y;
	});
	ans=a[1];
	for(int i=2;i<=m;i++) ans&=a[i];
	cout<<ans<<'\n';
	return 0;
}
