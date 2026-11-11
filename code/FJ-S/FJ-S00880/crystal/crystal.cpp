#include<bits/stdc++.h>
using namespace std;
struct shui{
	long long zhi;
	int liang;
}a[500001];
long long b[500001];
int n,cnt;
long long m;
bool cmp(shui a,shui b){
	return a.zhi<b.zhi;
}
int main(){
freopen("crystal.in","r",stdin);
freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	sort(b+1,b+1+n);
	for(int i=1;i<=n;i++){
		if(b[i]!=a[cnt].zhi){
			a[++cnt].zhi=b[i];
			a[cnt].liang++;
		}else{
			a[cnt].liang++;
		}
	}
	int j=1,sum=0,liang=0;
	long long he=0;
	for(int i=1;i<=cnt;i++){
		he+=liang*(a[i].zhi-a[i-1].zhi);liang+=a[i].liang;
		if(he<=m){
			sum=max(sum,liang);
		}else{
			while((he-(a[i].zhi-a[j].zhi)*a[j].liang)>=m){
				he-=(a[i].zhi-a[j].zhi)*a[j].liang;
				liang-=a[j].liang;
				j++;
			}
			while(he>m){
				he-=(a[i].zhi-a[j].zhi);
				a[j].liang--;
				liang--;
				if(a[j].liang==0)j++;
			}
			sum=max(sum,liang);
		}
	}
	cout<<sum;
	return 0;
}
