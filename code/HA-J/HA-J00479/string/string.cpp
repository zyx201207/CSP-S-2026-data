#include<bits/stdc++.h>
using namespace std;
long long n,a[200010],h,cnt;
char b[200010];
int fun(int x,int y){
	int l=x,r=y;
	while(l<=r){
		if(b[r]!=b[l]){
			if(b[l]==0){
				l++;
			}
			else{
				b[r]=b[l];
				cnt+=a[r];
			}
			cout<<cnt<<"\n";
		}
		if(a[l]>a[r]){
			a[r-1]=a[r-1]-(a[l]-a[r]);
			cnt+=(a[l]-a[r]);
			a[r]+=(a[l]-a[r]);
		}
		if(a[l]<a[r]){
			a[r-1]=a[r-1]+(a[r]-a[l]);
			a[r]=a[l];
		}
		l++;
		r--;
	}
	cout<<cnt<<"\n";
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	h=n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	for(int i=1;i<n;i++){
		if(b[i]==b[i+1]){
			b[i]=0;
			h--;
			a[i+1]=a[i]+a[i+1];
			a[i]=0;
		}
	}
	if(h==1){
		cout<<"0\n";
		return 0;
	}
	fun(1,n);
	return 0;
}
