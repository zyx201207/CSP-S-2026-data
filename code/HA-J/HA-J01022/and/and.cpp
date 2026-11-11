#include<bits/stdc++.h>
using namespace std;
long long  a[200000],b[200000];
long long n,m,ans,s,w;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	if(m==n){
		cin>>ans;
		for(int i=1;i<n;i++){
			cin>>s;
			ans=ans&s;
		}
		cout<<ans;
		return 0;
	}
	if(m==1){
		for(int i=0;i<n;i++){
			cin>>s;
			if(ans<s)ans=s;
		}
		cout<<ans<<endl;
		return 0;
	}
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(m==n-1){
		for(int j=0;j<n;j++){
		if(a[j]>b[1]){
			b[1]=a[j];
			w=j;
		}
		if(w==1)ans=a[0];
		else ans=a[1];
		for(int j=0;j<n;j++){
			if(j!=w)ans=ans&a[j];
		}
		cout<<ans;
		return 0;
	}
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
		if(a[j]>b[i]){
			b[i]=a[j];
			w=j;
		}
		a[w]=-1;
	}
	}
	ans=b[0];
	for(int i=1;i<m;i++){
		ans=ans&b[i];
	}
	cout<<ans;
	return 0;
} 
