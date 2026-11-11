/*
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=2e5+10;
ll a[N],b[N],c[N];
ll etoshi(ll x){
	ll cnt=0;
	while(x){
		x/=2;
		cnt++;
	}return cnt;
}
int main(){
	//freopen("and.in","r",stdin);
	//freopen("and.out","w",stdout); 
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=etoshi(a[i]);
	}
	sort(b+1,b+1+n,greater<int>());
	for(int i=1;i<=n;i++){
		if(i==1){
			c[i]=0;
		}
		else{
			c[i]=b[i]-b[i-1];
		}
	}
	
	return 0;
}*/
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=2e5+10;
ll a[N];
ll b[31];
void dabiao(){
	int nw=1;
	b[0]=1;
	for(int i=1;i<=30;i++){
		b[i]=nw*2;
		nw*=2;
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout); 
	int n,m;
	cin>>n>>m;
	dabiao();
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,greater<int>());
	int ans=-1;
	for(int i=1;i<=m;i++){
		bool flg=true;
		for(int j=0;j<=30;j++){
			if(a[i]==b[j]){
				if(i<m && a[i+1]==a[i]){
					flg=true;break;
				}
				else{
					flg=false;
					m++;
					break;
				}	
			}
		}
		if(flg){
			if(ans==-1){
				ans=a[i];
			}
			ans=ans&a[i];
		}
	}
	//cout<<b[30]<<endl;
	cout<<ans;
	return 0;
}
