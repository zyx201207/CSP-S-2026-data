#include<bits/stdc++.h> 
using namespace std;
long long n,L=0,a[200010],ans=0;
char c[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","r",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		L+=a[i];
	}
	long long i=1,j=n,s=a[i];
	while(s<=L/2){
		s+=a[i+1];
		while(a[i]<a[j]){
			if(c[i]!=c[j])
				ans+=a[j];
			a[i]-=a[j];
			j--;
		}
		if(c[i]!=c[j])
			ans+=a[i];
		a[j]-=a[i];
		i++;
	}
	printf("%lld",ans);
	return 0;
}
