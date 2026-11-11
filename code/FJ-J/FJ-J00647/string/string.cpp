#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],b[200005];
char c[200005],d[200005];
long long  ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	if(n==1){
		cout<<"0";
		return 0;
	}
	for(int i=0;i<n;i++){
		cin>>b[i]>>d[i];
	}
	int o=0;
	for(int i=0;i<n;i++){
		a[o]+=b[i];
		c[o]=d[i];
		if(d[i]!=d[i+1]){
			o++;
		}
	}
	if(o==1){
		cout<<"0";
		return 0;
	}
	long long l=0,r=o-1;
	while(l<r){
		if(a[l]>a[r]){
			ans+=a[r];
			a[l]-=a[r]; 
			r--;
		}
		else if(a[l]<a[r]){
			ans+=a[l];
			a[r]-=a[l];
			l++;
		}
		else{
			ans+=a[l];
			l++;
			r--;
		} 
	}
	cout<<ans;
} 
