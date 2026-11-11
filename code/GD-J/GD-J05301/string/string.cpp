#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,a[200001];
	char c[200001];
	cin>>n;
	long long ans=0,cnt=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		ans++;
	}
	long long r=1,l=ans;
	while(r<l){
		if(a[r]>=a[l]){
			if(c[l]!=c[r]) cnt+=a[l];
			a[r]-=a[l];
			l--;
			if(!a[r]) r++;
		}else{
			if(c[l]!=c[r]) cnt+=a[r];
			a[l]-=a[r];
			r++;
		}
	}
	cout<<cnt<<endl;
	return 0;
}
