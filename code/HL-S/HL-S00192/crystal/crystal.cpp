#include<bits/stdc++.h>
using namespace std;
const int N=500010;
long long n,m,a[N],s[N],sum,maxi,t,tf=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1); 
	for(int i=n;i>=2;i--){
		sum=0;
		t=0;
		tf=1;
		for(int j=1;j<=i-1;j++){
			s[j]=a[i]-a[j];
		} 
		sort(s+1,s+i);
		for(int j=1;j<=i-1;j++){
			if(sum+s[j]<=m){
				sum+=s[j]; 
			}else{
				t=j-1;
				tf=0;
				break;
			} 
		} 
		if(sum<=m && tf==1){
			t=i-1;
		} 
		t++;
		maxi=max(maxi,t);
		for(int k=1;k<=n;k++){
			s[k]=0;
		}
	}
	cout<<maxi;
	return 0;
} 
