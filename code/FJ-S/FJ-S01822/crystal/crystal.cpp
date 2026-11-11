#include<bits/stdc++.h>
using namespace std;
int a[500010];
int n,m,f,c;
bool cmp(int a,int b){
	return a<b;
}
void ts(){
	int sum=0,p=1;
	while(sum<m){
		p++;
		sum=c*p*(p-1)/2;
	}
	cout<<p-1;
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i==2){
			c=a[i]-a[i-1];
		}
		if(i>2&&f==0){
			if(a[i]-a[i-1]!=c){
				f=1;
			}
		}
	}
	if(f==0){
		ts(); 
		return 0; 
	}
	sort(a+1,a+n+1,cmp);
	int ans=0;
	for(int i=1;i<=n;i++){
		int p=i,t=m,sum=0;
		while(t>0&&p>0){
			t-=(a[i]-a[p]);
			p--;
			if(t>=0)sum++;
		}
		ans=max(ans,sum);
	}
	cout<<ans;
	return 0;
}
