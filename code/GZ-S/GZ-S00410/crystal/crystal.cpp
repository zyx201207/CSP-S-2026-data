//GZ-S00410 ª∆∫∆è™
#include<bits/stdc++.h>
using namespace std;
long long a[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	long long ma=0,la=m,no=1;
	priority_queue<long long ,vector<long long>,greater<long long> > b;
	b.push(a[0]);ma=1;
	for(int i=1;i<n;i++){
		while(!b.empty()&&(a[i]-a[i-1])*no>la){
			la+=a[i-1]-b.top();
			b.pop();
			no--;
		}
		la-=(a[i]-a[i-1])*no;
		b.push(a[i]);
		no++;
		ma=max(ma,no);
	}cout<<ma;
}
