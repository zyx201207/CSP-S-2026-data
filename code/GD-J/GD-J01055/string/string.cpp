#include<iostream>
using namespace std;
int n,l=1;
long long ans=0;
long long a[2000009],u[2000009];
char b[2000009],u1[2000009];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int r=n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	} 
	while(r-l>=1||r!=l){
		if(a[l]==a[r]){
			if(b[l]!=b[r]){
				ans+=a[l];
				l++;
				r--;
			}
		}else if(a[l]<a[r]){
			    if(b[l]!=b[r]){
				    ans+=a[l];
			    }
			    a[r]-=a[l];
			    l++;
		    }else if(a[l]>a[r]){
			    if(b[l]!=b[r]){
				    ans+=a[r];
			    }
			    a[l]-=a[r];
			    r--;
		    }

	}
	cout<<ans;
	return 0;
}
