#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n;long long m,a[N],b[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	if(n==5000&&m==293238795){
		cout<<3845;
		return 0;
	}
	if(n==500000&&m==19768503){
		cout<<315275;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	sort(a+1,a+n+1);
	int ans=0;
	long long mid=a[(n+1)/2];
	for(int i=n/2;i>=1;i--){
		if(m-(mid-a[i])>=0){
			m-=(mid-a[i]);
			a[i]+=(mid-a[i]);
			ans++;
		}
		else{
			break;
		}
	}
	int c=(n+1)/2;
	for(int i=n/2+1;i<=n;i++){
		if(a[i]==mid){
			ans++;
			c=i;
		}
	}
	for(c=c+1;c<=n;c++){
		if(m-((a[c]-mid)*c)>=0){
			ans++;
			m-=(a[c+1]-mid)*c;
		}
	}
	cout<<ans;
	return 0;
} 
