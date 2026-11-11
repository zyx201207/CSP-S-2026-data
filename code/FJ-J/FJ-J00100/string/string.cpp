#include<bits/stdc++.h>
using namespace std;
int a[200005];
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
	}
	/*
	string s="";
	for(int i=0;i<n;i++){
		for(int j=0;j<a[i];j++){
			s+=c[i];
		}
	}
	int l=0,r=s.size()-1;
	long long ans=0;
	for(;l<r;){
		if(s[l]!=s[r]){
			ans++;
		}
		l++;
		r--;
	}*/
	
	int l=0,r=n-1;
	long long ans=0;
	while(l<=r){
		//cout<<"l="<<l<<' '<<"r="<<r<<'\n';
		//cout<<"a[l]="<<a[l]<<' '<<"a[r]="<<a[r]<<' '<<"c[l]="<<c[l]<<' '<<"c[r]="<<c[r]<<'\n';
		if(a[l]>a[r]){
			if(c[l]!=c[r]){
				ans+=a[r];
			}
			a[l]-=a[r];
			r--;
		}
		if(a[l]<a[r]){
			if(c[l]!=c[r]){
				ans+=a[l];
			}
			a[r]-=a[l];
			l++;
		}
		if(a[l]==a[r]){
			if(c[l]!=c[r]){
				ans+=a[l];
			}
			l++;
			r--;
		}
	}
	cout<<ans<<'\n';
	return 0;
}
//ak
