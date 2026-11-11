#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+10;
ll n,m,ans;
ll a[N],b[N];
bool cmp(ll a,ll b){
	return a<b;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	for(ll i=1;i<n;i++){
		b[i]=a[i]-a[i+1];
	}for(ll i=1;i<n;i++){
		ll maxpd=0,j;
		for(j=i;;){
			maxpd+=b[j]*(j-i+1);
			if(abs(maxpd)>m||j>=n) break;
			j++;
			//cout<<"when i="<<i<<" ,j="<<j<<" ,maxpd:"<<maxpd<<'\n';
		}ans=max(ans,j-i+1);
		//cout<<"while was finished. j:"<<j<<" i:"<<i<<'\n';
		//cout<<a[j+1]<<' '<<a[j]<<endl;
		for(int k=j+1;;k++){
			if(a[k]==a[j]) ans++;
			else break;
			//cout<<"a[k]:"<<a[k]<<" a[j]:"<<a[j]<<'\n';
		}
	}cout<<ans;
	return 0;
} 
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/
