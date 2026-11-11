#include <bits/stdc++.h>
using namespace std;
int main(){
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	
	int n,m,ans=0,flg,a[200086],b[200086];
	
	cin>>n>>m;
	
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	
	sort(a,a+n);
	
	flg=a[0];
	b[0]=0;
	
	for(int i=0;i<n;i++){
		a[i]=a[i]-flg+1;
	}
	
	for(int i=0;i<n;i++){
		b[i+1]=b[i]+a[i];
	}
	
	for(int i=0;i<n;i++){
		
		if(m-b[i]>=0){
			m-=b[i];
			ans++;
		}else{
			break;
		}
		
	}
	
	cout<<ans;
}
