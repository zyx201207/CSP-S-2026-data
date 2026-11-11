#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
long long a[200005];
long long mx=-1e13;
long long mi=1e13;
long long ans;
long long ans_1;
bool b;
bool check(long long mid){
	int b[n+5];
	for(int i=1;i<=n;i++){
		b[i]=a[i];
	}
	long long step=0;
	int l=lower_bound(b+1,b+n+1,mid)-b;
	while(step<m&&l>=1){
		if(b[l]<mid){
			b[l]++;
			step++;
		}else{
			l--;
		}
	}
	if(l==1&&step!=m){
		return false;
	}
	ans_1=0;
	for(int i=n;i>=1;i--){
		if(b[i]==mid){
			ans_1++;
		}
	}
	if(l<1&&step!=m) return false;
	if(ans_1>ans) return true;
	else return false;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==a[i-1]) b=1;
		else b=0;
		mx=max(mx,a[i]);
		mi=min(mi,a[i]);
	}
	if(b){
		cout<<n;
		return 0;
	}
	sort(a+1,a+n+1);
	int x_2=n;
	if(x_2%2!=0) x_2++;
	long long l=mi,r=(2*a[x_2/2])-mi;
	while(l<=r){
		long long mid=(r+l)>>1;
		if(check(mid)){
			ans=max(ans,ans_1);
			r=mid; 
		}else{
			l=mid+1;
		}
	}
	cout<<ans;
	return 0;
}
