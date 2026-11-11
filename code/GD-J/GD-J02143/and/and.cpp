#include<bits/stdc++.h>
using namespace std;
int c1(int n){
	int cnt=0;
	while(n){
		if(n%2==1){
			cnt++;
		}
		n/=2;
	}
	return cnt;
}
int n,m,ans;
struct num{
	int k,cnt;
}a[200010];
bool cmp(num a,num b){
	if(a.cnt!=b.cnt){
		return a.cnt>b.cnt;
	}
	return a.k>b.k;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i].k;
		a[i].cnt=c1(a[i].k);
	}
	sort(a,a+n,cmp);
	ans=a[0].k;
	for(int i=0;i<m;i++){
		ans&=a[i].k;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
