#include<iostream>
#include<algorithm>
using namespace std;
#define N 200005
#define int long long
int a[N];
bool cmp(int a,int b){
	return a>b;
}
int ps2[50];
int js(int n){
	int cnt=0;
	while(n){
		n/=2;
		cnt++;
	}
	return cnt;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++){
		//cout<<a[i]<<" "<<js(a[i])<<endl;
		int s=js(a[i]);
		if(i-ps2[s]>=m){
			cout<<a[i];
			return 0;
		}
		if(a[i]==(1ll<<s)-1) continue;
		for(int j=0;j<=31;j++){
			if(a[i]>(1ll<<j)-1){
				ps2[j]++;
			}
			else break;
		}
	}
	return 0;
} 
