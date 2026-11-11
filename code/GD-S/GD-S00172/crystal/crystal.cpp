#include<bits/stdc++.h>
using namespace std;
long long n,a[500005],k;
bool cmp(int a,int b){
	return a<b;
}
int maxx=-1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	for(int i=2;i<=n;i++){
		int ans=1,m=k;
		for(int j=i-1;j>=1;j--){
			if(a[i]-a[j]<=m){
				m-=a[i]-a[j];
				ans++;
			}else{
				break;
			}
		}
		maxx=max(ans,maxx);
	}
	cout<<maxx<<endl;
	return 0;
} 
