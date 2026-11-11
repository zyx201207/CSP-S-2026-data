#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
int n,m;
int a[200005],ans;
bool A=1,B=1,C=1;
int cnt[35];
void solve(int last,vector<int>now){
	memset(cnt,0,sizeof(cnt));
	for(int i = 0;i < now.size();i++){
		long long j=a[i];
		while(j){
			cnt[(int)log2(j&-j)]++;
			j-=(j&-j);
		}
	}
	int maxid=0;
	for(int i = 0;i <= last;i++) if(cnt[i]>=m) maxid=i;
	if(cnt[maxid]<m) return;
	ans+=pow(2,maxid);
	vector<int>temp;
	for(int i = 0;i < now.size();i++) if((now[i]>>maxid)&1) temp.push_back(now[i]);
	solve(maxid-1,temp);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
//		cout<<(int)pow(2,(int)log2(a[i]+1))-1<<'\n';
		if((int)pow(2,(int)log2(a[i]+1))-1!=a[i]) A=0;
		if(a[i]!=i-1) B=0; 
		if(a[i]>4) C=0;
	}
	if(m==1) for(int i = 1;i <= n;i++) ans=max(ans,a[i]);
	else if(m==n){
		ans=a[1];
		for(int i = 2;i <= n;i++) ans&=a[i];
	}	
	else if(A){
		sort(a+1,a+n+1);
		ans=a[n];
		for(int i = n-1;i >= n-m+1;i--) ans&=a[i];
	}
//	else if(B && (int)pow(2,(int)log(n)))
	else if(C){
		for(int i = 1;i <= n;i++) cnt[a[i]]++;
		if(cnt[3]>=m) ans=3;
		else if(cnt[2]+cnt[3]>=m) ans=2;
		else if(cnt[1]+cnt[3]>=m) ans=1;
		else ans=0;
	}
	else if(m==2) for(int i = 1;i <= n;i++) for(int j = i+1;j <= n;j++) ans=max(ans,a[i]&a[j]);
	else{
		vector<int>temp;
		for(int i = 1;i <= n;i++) temp.push_back(a[i]);
		solve(n,temp);
	}
	cout<<ans;
	return 0;
}
