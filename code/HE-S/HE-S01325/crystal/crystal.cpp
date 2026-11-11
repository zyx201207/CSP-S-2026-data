#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500000],s[500000];
long long cnt=1;
long long i=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=0;i<n;i++){
		cin>>a[i];
	}
	while(m){
		if(a[i]==a[i+1]){
			cnt+=1;
			i++;
		}
		else{
			a[i]+=1;
			m--;
		}
	}
	cout<<cnt;
	return 0;
} 
