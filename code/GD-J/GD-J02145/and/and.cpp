#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
int num[maxn],sum[31],n,m,ans; 
bool cmp(int x,int y){
	for(int k=29;k>=0;k--){
		if(sum[k]<m)continue;//否则无论如何选数都是 0
		if((x&(1<<k))>(y&(1<<k)))return true;
		if((x&(1<<k))<(y&(1<<k)))return false;
	}
	return true;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>num[i];
		for(int k=0;k<=29;k++)sum[k]+=((num[i]&(1<<k))!=0);
	}
	sort(num+1,num+n+1,cmp);
	for(int i=1;i<=m;i++){
		if(i==1)ans=num[i];
		else ans=(ans&num[i]);
	}
	cout<<ans<<"\n";
	return 0;
}
/*
注意到：
2^n > Σ2^k (k∈0~(n-1)) 
所以选一个高位，一定比选很多个低位更加优秀
1000...0000 better than 0111...1111
模拟即可 
*/
