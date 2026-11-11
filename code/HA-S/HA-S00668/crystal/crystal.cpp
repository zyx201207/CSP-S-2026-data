#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;
const int maxn=5e5+5;
ll a[maxn];
ll cop[maxn];
ll siz[maxn];
ll daijia[maxn];
ll n,m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cop[i]=a[i];
	}
	sort(a+1,a+1+n);
	sort(cop+1,cop+1+n);
	int cnt=unique(a+1,a+1+n)-a-1;
	for(int i=1;i<=cnt;i++){
		int temp=lower_bound(cop+1,cop+1+n,a[i])-cop;
		for(int j=temp;cop[j]==a[i];j++){
			siz[i]++;
		}
		siz[i]+=siz[i-1];
		daijia[i]=daijia[i-1]+(ll)siz[i-1]*(a[i]-a[i-1]);
	}
//	for(int i=1;i<=cnt;i++){
//		cout<<a[i]<<" "<<siz[i]<<" "<<daijia[i]<<endl;
//	}
	ll sum=0;
	for(int i=1;i<=cnt;i++){
		int l=1,r=i,ans=n+1;//don't forget to add own siz
		ll temp=0;
		while(l<=r){
			int mid=l+(r-l)/2;
			temp=daijia[i]-daijia[mid]-(ll)(a[i]-a[mid])*siz[mid-1];
			if(temp>m){
				l=mid+1;
			}
			else if(temp==m){
				ans=mid;
				break;
			}
			else{
				r=mid-1;
				ans=mid;
			}
		}
		ll res=0;
		if(m>temp&&ans!=i&&ans!=1){
			res=(m-temp)/(a[i]-a[ans-1]);
		}
		sum=max(sum,siz[i]-siz[ans-1]+res);
	}
	cout<<sum;
	return 0;
}
/*
5 5
1 2 4 8 9
*/

