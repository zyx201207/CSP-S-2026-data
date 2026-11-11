#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,a[200005],h;
	char b[200005];
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		h+=a[i];
		if(b[i]==b[i-1]){
			a[i-1]+=a[i];
			i--;
			n--;
		}
	}
	long long cha,he=0,sum=0,r=n;
	for(int i=1;he<=h/2;i++){
		if(a[r]>a[i]){
			swap(a[r],a[i]);
			swap(b[r],b[i]);
		}
		cha=a[r]-a[i];
		a[r]=a[i];
		b[r]=a[i];
		for(int j=r-1;cha>0;j--){
			if(cha>=a[j]){
				cha-=a[j];
				if(b[j]!=b[i]) sum+=a[j];
				a[j]=0;
				r--;
			}else{
				a[j]-=cha;
				if(b[j]!=b[i]) sum+=cha;
				cha=0;
			}
		}
		he+=a[i];
	}
	cout<<sum;
	return 0;
} 
