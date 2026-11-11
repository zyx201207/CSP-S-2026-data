#include<bits/stdc++.h>
using namespace std;
long long a[500005];
long long ans=1;
void jia(int x,int y){
	for(int i=1;i<x;i++){
		a[i]=a[i]+y;
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int mm=m;
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
	//cout<<i<<" ";
		if(mm==0) break;
		int s=(a[i]-a[i-1])*(i-1);
		if(mm>=s){
			//cout<<"+"<<s<<" "<<m<<"\n";
			jia(i,(a[i]-a[i-1]));	
			mm=mm-s;
		}
	}
	//cout<<"***"<<2;
	for(int i=2;i<=n;i++){
		if(a[i]==a[i-1]) ans++;
	}
	//for(int i=1;i<=n;i++) cout<<a[i]<<" ";
	cout<<ans;
	
	return 0;
}
