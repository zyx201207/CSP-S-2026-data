#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ll n;
	cin>>n;
	ll a[n],sum=0,kk=0,answer=0;
	char num[n];
	for(int i=0;i<=n-1;i++){
		cin>>a[i]>>num[i];
		sum+=a[i];
	}
	ll jl=0;
	for(int i=n-1;i>=0;i--){
		while(a[i]){
			if(i==kk){
				break;
			}
			if(a[i]>=a[kk]){
				if(num[i]!=num[kk]){
					answer+=a[kk];
				}
				a[i]-=a[kk];
				jl+=a[kk];
				kk++;
			}else{
				if(num[i]!=num[kk]){
					answer+=a[i];
				}
				jl+=a[i];
				a[kk]-=a[i];
				a[i]=0;
			}
		}
		if(i==kk){
			break;
		}
	}
	cout<<answer;
	return 0;
}

