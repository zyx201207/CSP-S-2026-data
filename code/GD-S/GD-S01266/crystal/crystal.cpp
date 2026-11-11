#include<iostream>
#include<algorithm>
using namespace std;
int n,m;
long long a[500005];
long long b[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	bool different=false;
	long long d=0;
	long long lastD=0;
	bool sameD=true;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]!=a[i-1])different=true;
		lastD=d;
		d=a[i]-a[i-1];
		if(lastD!=d)sameD=false;
		b[i]=a[i];
	}
	if(!different){
		cout<<n;
		return 0;
	}
	if(sameD){
		cout<<m/d;
	}
	sort(a,a+n,greater<int>());
	int all=0;
	for(int i=1;i<n;i++){
		all+=abs(a[i]-a[0]);
	}
	if(all<=m){
		cout<<n;
		return 0;
	}
	long long last=0;
	for(int i=0;i<n;i++){
		int k=m;
		int pos=i+1;
		int ans=1;
		while(k>0&&pos<n){
			k-=abs(a[i]-a[pos++]);
			if(k<0)break;
			ans++;
		}
		if(ans>last){
			//cout<<a[i]<<" "<<a[pos-1]<<" "<<ans<<" "<<k<<" "<<endl;
			last=ans;
		}
	}
	cout<<last;
	return 0;
} 
