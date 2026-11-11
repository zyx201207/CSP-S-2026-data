#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	long long n,k,s=0,e,sum=0;
	cin>>n;
	k=n;
	e=n;
	long long a[n];
	char b[n];
	for(long long i=0;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	while(!(((e-1)-s)<=0)){
		if(b[e-1]==b[s]){
			if(a[s]>a[e-1]){
				a[s]-=a[e-1];
				e--;
			}
			else if(a[s]<a[e-1]){
				a[e-1]-=a[s];
				s++;
			}
			else if(a[s]==a[e-1]){
				e--;
				s++;
			}
		}
		else{
			if(a[s]>a[e-1]){
				sum+=a[e-1];
				a[s]-=a[e-1];
				e--;
			}
			else if(a[s]<a[e-1]){
				sum+=a[s];
				a[e-1]-=a[s];
				s++;
			}
			else if(a[s]==a[e-1]){
				sum+=a[s];
				e--;
				s++;
			}
		}
	}
	cout<<sum;
	
	return 0;
}
