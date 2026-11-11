#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,a[20001],sum=0,m;
	string s[20001];
	cin>>n;
	for(int N=1;N<=n;N++){
		cin>>a[N]>>s[N];
	}
	for(int N=1,N2=n;N<N2;){
		if(s[N]!=s[N2]){
			if(a[N]==a[N2]){
				sum+=a[N2];
				N++,N2--;
			}else if(a[N]<a[N2]){
				sum+=a[N];
				a[N2]-=a[N];
				N++;
			}else if(a[N]>a[N2]){
				sum+=a[N2];
				a[N]-=a[N2];
				N2--;
			}
		}else if(s[N]==s[N2]&&a[N]!=a[N2]){
			if(a[N>a[N2]]){
				a[N]-=a[N2];
				N2--;
			}else{
				a[N2]-=a[N];
				N++;
			}
		}else if(s[N]==s[N2]&&a[N]==a[N2]){
			N++,N2--;
		}
	}
	cout<<sum;
	return 0;
}
