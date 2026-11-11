#include<bits/stdc++.h>
using namespace std;
long long n,s=0;long long a[200005];char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int h=1,t=n;
	while(h<t){
		if(c[h]!=c[t]){
			if(a[h]>a[t]){a[h]-=a[t],s+=a[t],t--;}
			else if(a[h]<a[t]){a[t]-=a[h],s+=a[h],h++;}
			else {s+=a[h],t--,h++;}
		}else{
			if(a[h]>a[t]){a[h]-=a[t],t--;}
			else if(a[h]<a[t]){a[t]-=a[h],h++;}
			else {t--,h++;}
		}
	}
	cout<<s;
	return 0;
}
