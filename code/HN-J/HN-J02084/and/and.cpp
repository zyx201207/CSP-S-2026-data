#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long a[N],n,m,maxj,maxn;
bool b[N][40],us[N],ans[N];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>m;
	maxn=n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++){
		long long j=0,s=a[i];
		while(s){
			b[i][++j]=s%2;
			s/=2;
		}
		maxj=max(maxj,j);
	}
	
	
	for(int j=maxj;j>0;j--){
		int cnt=0;
		for(int i=1;i<=maxn;i++){
			if(cnt>=m){
				maxn=i-1;
				break;
			}
			if(b[i][j])cnt++;
		}
		if(cnt>=m)ans[j]=1;
		else ans[j]=0;
	}
	
	
	long long summ=0;
	for(int i=1;i<=maxj;i++){
		if(ans[i]){
			summ+=pow(2,i-1);
		}
	}
	cout<<summ;
	return 0;
} 
