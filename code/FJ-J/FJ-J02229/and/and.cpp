#include<bits/stdc++.h>
using namespace std;
int m,n;
int a[200002];
int a1[200002];
bool b=1,tb;
int tb1;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<=448;i++){
		if(pow(2,i)==n){
		tb=1;tb1=i;
		break;}
	}
	for(int i=0;i<n;i++){
		cin>>a[i];
		a1[i]=a[i]+1;
		
	}
	sort(a,a+n);
	for(int i=0;i<n;i++){
		if(b){
			while(a1[i]>1){
				if(a1[i]==7)
				if(a1[i]%2==1){
				b=0;break;}
				a1[i]/=2;
			}
		}
	}
	for(int i=0;i<n;i++){
		if(a[i]!=i){
			tb=0;break;
		}
	}
	if(m==1){
	    cout<<a[n-1];
	    return 0;
	}
	int ans=0;
	if(m==n){
		for(int i=1;i<n;i++){
			a[i]=a[i-1]&a[i];
		}cout<<a[n-1];
		return 0;
	}
	if(m==2){
		for(int i=0;i<n-1;i++){
			for(int j=i+1;j<n;j++){
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans;
		return 0;
	}
	if(b){
		cout<<a[n-m];
		return 0;
	}
	
	if(tb=1){
		if(m<=tb1)cout<<pow(2,tb1+1-m)-1;
		else cout<<0;
		return 0;
	}
	cout<<0;
	return 0;
}

