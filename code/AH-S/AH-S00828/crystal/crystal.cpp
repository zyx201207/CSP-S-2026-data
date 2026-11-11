#include <bits/stdc++.h>
using namespace std;
long long a[500005],tmp[500004];
long long n,m;
long long px(int i,long long s){
	int cnt=tmp[2]; 
	 for(int j=i;j<n;j++){
	 	cnt+=tmp[i]+a[i+1]*2;
	 	if(s<cnt){
	 		return j-i+3;
		}
	 }
}
int main (){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >>n >>m;
	long long ans=0;
	bool s1=1,s2=1;
	cin >>a[1] >>a[2];
	int cnt1=(a[2]-a[1]);
	for(int i=3;i<=n;i++){
		cin >>a[i];
		if(a[i]!=i){
			s1=0;
		}
		if(a[i]-a[i-1]!=cnt1){
			s2=0;
		}
	}
	if(n<=16){
		sort(a+1,a+1+n);
		for(int i=1;i<n;i++){
			tmp[i]=a[i+1]-a[i];
		}
		if(m<tmp[1]){
			cout <<1;
			return 0;
		}
		for(int i=1;i<=n;i++){		
			ans=max(ans,px(i,m));
		}
		cout <<ans;
		return 0;
	}
	if(s1||s2){
		long long kk=1;
		if(m<cnt1){
			cout <<1;
			return 0;
		}
		if(cnt1>=0){
			ans=a[1];
			while(m>ans){
				ans=ans+a[1]+cnt1*(kk);
				kk++;
			}
			cout <<kk;
		return 0;
		}
		else{
			ans=a[n];
			while(m>ans){
				ans=ans+a[n]+cnt1*(-kk);
				kk++;
			}
		cout <<kk;
		return 0;
		}
		
	} 
	return 0;
}
