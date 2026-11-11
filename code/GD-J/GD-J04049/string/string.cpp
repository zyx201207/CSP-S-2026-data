#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n;
char c[N];
long long sum,a[N],ans=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		sum+=a[i];
	}
	int i=1,j=n;
	long long l=1,r=sum,lused=0,rused=0;
	while(i<j){
		if(a[i]>a[j]){
			if(c[i]!=c[j])
				ans+=a[j];
			a[i]-=a[j--];
		}
		else{
			if(c[i]!=c[j])
				ans+=a[i];
			a[j]-=a[i++];
		}
	}
	cout<<ans;
	return 0;
} 
