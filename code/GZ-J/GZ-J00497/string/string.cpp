//GZ-J00497 遵义市第八中学 龙长鑫 
#include<bits/stdc++.h>
using namespace std;
int a[200005];
char b[200005];
long long n,sum=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
cin>>n;
long long zd=n-1;
for(int i=0;i<n;i++) cin>>a[i]>>b[i];
for(int i=0;i!=zd; ){
	if(b[i]==b[zd-i]){
		if(a[i]>a[zd-i]){
			a[i]-=a[zd-i];
			a[zd-i]=0;
			zd--;
		}else{
			a[zd-i]-=a[i];
			a[i]=0;
			i++;
		}
	}else{
		if(a[i]>a[zd-i]){
			sum+=a[zd-i];
			a[i]-=a[zd-i];
			a[n-i-1]=0;
			zd--;
		}else{
			sum+=a[i];
			a[zd-i]-=a[i];
			a[i]=0;
			i++;
		}
	}
}
cout<<sum;
	return 0;
}


