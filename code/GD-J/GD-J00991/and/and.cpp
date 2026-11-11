#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
const int N=2e5+10;
int n,m;
long long int a[N];
long long int ovo[N][45],sum[45],MAXX[N][3],MAXXX[N];
void dg(long long int x,int I){
	int jz2[40];
	long long int t=x,l=0;
	while(t){
		l++;
		jz2[l]=t%2;
		t/=2;
	}
	for(int i=0;i<l;i++){
		ovo[I][i]=jz2[i+1];
		sum[i]+=jz2[i+1];
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		MAXX[i][1]=i;
		dg(a[i],i);
	}
	int maxjz=0;
	for(int i=0;i<=35;i++){
		if(sum[i]>=m){
			maxjz=i;
		}
	}
	int L=n,l=n,maxn=0;
	while(l>m){
		l=0;
		maxn=0;
		for(int i=1;i<=L;i++){
			if(ovo[MAXX[i][1]][maxjz]==1){
				maxn++;
			}
		}
		if(maxn<m){
			maxjz--;
			continue;
		}
		for(int i=1;i<=L;i++){
			if(ovo[MAXX[i][1]][maxjz]==1){
				MAXX[++l][0]=a[MAXX[i][1]];
				MAXX[l][1]=MAXX[i][1];
			}
		}
		for(int i=1;i<=l;i++){
			MAXXX[i]=MAXX[i][0];
		}
		L=l;
		maxjz--;
	}
	int ans=MAXXX[1];
	for(int i=2;i<=L;i++){
		ans=ans&MAXXX[i];
	}
	cout<<ans;
	return 0;
}
