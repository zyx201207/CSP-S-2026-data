#include<bits/stdc++.h>
using namespace std;

const int maxn=500005;

int n,base=0;
bool A=true;
long long m,a[maxn],cha[maxn],ans;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i==1) base=a[i];
		if(a[i]!=base) A=false;
	}
	if(A){
		cout<<n;
		return 0;
	}
	for(int i=1;i<=n;i++){
		long long t=m, tmpans=0;
		for(int j=1;j<=n;j++){
			cha[j]=a[i]-a[j];
		}
//		cout<<a[i]<<" ";
//		for(int j=1;j<=n;j++) cout<<cha[j]<<" ";
//		cout<<"\n";
		sort(cha+1, cha+n+1);
		for(int j=1;j<=n;j++){
			if(cha[j]<0) continue;
			if(t-cha[j]<0){
//				cout<<a[i]<<" "<<t<<" "<<cha[j]<<" "<<tmpans<<"\n";
				break;
			}
//			cout<<tmpans<<" "<<t-cha[j]<<"\n";
			tmpans++;
			t-=cha[j];
		}
//		cout<<a[i]<<" ";
//		for(int j=1;j<=n;j++) cout<<cha[j]<<" ";
//		cout<<"\n";
		if(tmpans>ans) ans=tmpans;
	}
	cout<<ans;
	return 0;
}
