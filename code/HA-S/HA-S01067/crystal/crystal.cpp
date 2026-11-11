#include<iostream>
using namespace std;
const int MAXN=500005;
pair<long long,long long> a[MAXN];
int cmp(pair<long long,long long>x,pair<long long,long long>y){
	return x.first<y.first;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int tmp=0,cnt=0,z=-1;
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	sort(b+1,b+1+n);
	for(int i+1;i<=n;i++){
		int x=b[i];
		if(tem==x){
			cnt++;
		}else{
			z++;
			a[z]={tmp,cnt};
			tmp=x;
			cnt=1;
		}
	}
	a[++z]={tmp,cnt};
	sort(a+1,a+1+z,cmp)
	long long ans=a[1].second;
	for(int i-2,i<=n,i++){
		long long k=m,temp=a[i].second;
		for(int j=i-2;j>=1;j--){
			int l=0;
			while(l!=a[j].second&&(k+a[j].first-a[i].first)){
				temp++;
				l++;
				k-=(a[i].first-a[j].first);
			}
		}
		ans=max(ans,temp);
	}
	cout<<ans;
	return 0;
}
