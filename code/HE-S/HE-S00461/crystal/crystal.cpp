#include <bits/stdc++.h> 
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,ans=0,cx=1;
	cin>>n>>m;
	int a[n+2];
	int abs1[n+3];
	int abs2[n+5];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=1;i<n;i++){
		abs1[i]=abs(a[i]-a[i-1]);
		if(abs1[i]==0){
			cx=cx+1;
		}
	}
	for(int i=1;i<n/2+1;i++){
		if(i%2==1){
			abs2[i]=abs1[i]+abs1[i+1];
		}
		else{
			abs2[i]=abs1[i];
		}
	}
	for(int j=2;abs2[j]<=m;j++){
		if(abs2[j]<=m){
			m-=abs2[j];
			ans++;
		}
	}
	cout<<ans+cx;//cxcs 
	return 0;
	fclose(stdin);
	fclose(stdout);//CSP
}
