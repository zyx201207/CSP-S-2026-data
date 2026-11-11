#include<bits/stdc++.h>
using namespace std;
long long w[500010];
long long cha[500010];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>w[i];
	}
	sort(w+1,w+1+n);
	//for(int i=2;i<=n;i++){
	//	cha[i]=w[i]-w[i-1];
	//}
	int maxn=-1000;
	int kns;
	for(int i=1;i<=n;i++){
		int hns=0;
		kns=0;
		for(int j=i-1;j>=1;j--){
			if(hns+w[i]-w[j]>m){
				break;
			}
			hns+=w[i]-w[j];
			kns++;
		}
		maxn=max(maxn,kns);
	}
	cout<<maxn+1;
	return 0;
}
