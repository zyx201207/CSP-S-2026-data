//GZ-J00628，邱光伍，贵阳市第三实验中学
#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
const int N=2*1e5+5;
ull n,m;
pair<ull,ull>a[N];
int zc(ull x){
	int sum=0;
	for(int i=x;i>0;i/=2){
		sum++;
	} 
	return sum;
}
bool cmp(pair<ull,ull>x,pair<ull,ull>y){
	return x.second<y.second;
}
int main(){
    freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(ull i=1;i<=n;i++){
		cin>>a[i].first;
		a[i].second=zc(a[i].first);
	}
	sort(a+1,a+n+1,cmp);
	int ans=a[1].first;
	for(ull i=2;i<=m;i++){
		//ans and a[i].first;
		cout<</*a[i].second<<" "<<*/a[i].first<<" ";
	} 
	cout<<ans;
	return 0;
} 
