#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
long long a[500005];
int n=0;
long long m=0;
long long ce(int ho){
	long long m1=m;
	long long q=0;
	long long ma=0;
	int pl=0;
	for(int j=0;j<n;j++){
		if(a[j]<=ho){
			ma=max(ma,a[j]);
			pl=j;
		}else if(a[j]>ho){
			break;
		}	
	}
	for(int j=pl;j>=0;j--){
		if(m1==0){
			break; 
		} 
		if(m1-(ho-a[j])>=0){
			q++;
			m1-=ho-a[j];
		}else{
			break;
		}
	}
	return q;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	long long ans=0;
	for(int i=0;i<n;i++){
		cin>>a[i]; 
	} 
	sort(a,a+n);
	for(int i=a[0];i<=a[n-1];i++){
		ans=max(ans,ce(i));
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
