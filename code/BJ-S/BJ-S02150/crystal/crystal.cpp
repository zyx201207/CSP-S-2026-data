#include<bits/stdc++.h>
using namespace std;
const int Maxn=5e5+10;
long long a[Maxn],m,n;
bool cmp(int a,int b){
	return a<b;}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	int ans=0,cha=a[2]-a[1],times=0;
	for(int i=1;i<=n;i++){
		if(times>m) break;
		else{
			ans++;
			times+=i*cha;
		}
	}
	cout<<ans;
	return 0;
}
