#include<bits/stdc++.h>
using namespace std;
long long n,ans,ed,answer;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	long long a[n+3];
	char c[n+3];
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		ans+=a[i];
	}
	long long i=1,j=n;
	while(ans>0){
		if(a[i]>a[j]){
			if(c[i]!=c[j]) answer+=a[j];
			ans-=(a[j]*2);
			a[i]-=a[j];
			a[j]=0;
			j--;
		}
		else if(a[i]==a[j]){
			if(c[i]!=c[j]) answer+=a[j];
			ans-=(a[j]*2);
			a[i]=0;
			a[j]=0;
			i++;j--;
		}
		else{
			if(c[i]!=c[j]) answer+=a[i];
			ans-=(a[i]*2);
			a[i]=0;
			a[j]-=a[i];
			i++;
		}
	}
	cout<<answer;
	return 0;
}
