#include<bits/stdc++.h>
using namespace std;

int a[200005];

int andn(int x,int y){
	string s1,s2;
	while(x>0){
		s1+='0'+x%2;
		x/=2;
	}
	while(y>0){
		s2+='0'+y%2;
		y/=2;
	}
	//cout<<s1<<' '<<s2<<' ';
	int sum=0;
	for(int i=1;i<=min(s1.size(),s2.size());i++){
		if(s1[i]==s2[i]&&s1[i]=='1'){
			sum+=pow(2,i);
		}
	}
	return sum;
}
int vis[1000000];
int main(){
	freopen("and.in","r",stdout);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	if(m==1){
		int maxn=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			maxn=max(maxn,a[i]);
		}
		cout<<maxn;
		return 0;
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		int maxn=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				maxn=andn(a[i],a[j]);
			}
		}
		cout<<maxn;
		return 0;
	}
	if(m==n){
		cin>>a[1];
		int ans=a[1];
		for(int i=2;i<=n;i++){
			cin>>a[i];
			ans=andn(ans,a[i]);
		}
		cout<<ans;
		return 0;
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		vis[a[i]]++;
		if(vis[a[i]]==2){
			ans=max(ans,a[i]);
		}
	}
	cout<<ans;
}
