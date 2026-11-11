#include<bits/stdc++.h>
using namespace std;
string s;
char b[2000005];
long long n,ans=0,a[2000005],x=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		if(i!=1&&b[i]!=b[i-1]){
			x=1;
		}
	}
	if(x==0){
		cout<<0;
		return 0;
	}
	long long l=1,r=n;

	while(r>l){

	if(a[l]>a[r]){
		if(b[l]!=b[r]){
			ans=ans+a[r];
			a[l]=a[l]-a[r];
			r--;
		}else{
			a[l]=a[l]-a[r];
			r--;
		}
	}
	else if(a[l]==a[r]){
		if(b[l]!=b[r]){
			ans=ans+a[l];

			r--;
			l++;
		}else{
			r--;
			l++;
		}
	}else{
		if(b[l]!=b[r]){
			ans=ans+a[l];
			a[r]=a[r]-a[l];
			l++;
		}else{
			a[r]=a[r]-a[l];
			l++;
		
		}

	}

}
	cout<<ans;
	return 0;
}
