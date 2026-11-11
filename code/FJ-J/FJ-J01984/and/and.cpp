#include<bits/stdc++.h>
using namespace std;
int num[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    int n,m;
	cin>>n>>m;
	long long a=-1;
	long long b=1073741825;
	for(int i=1;i<=n;i++){
		cin>>num[i];
		if(num[i]<b){
			b=num[i];
		}
		else if(num[i]>a){
			a=num[i];
		}
	}
	if(n==m){
		cout<<b;
		return 0;
	}
	if(m==1){
		cout<<a;
		return 0;
	}
	sort(1+num,num+n+1);
	cout<<num[n-m+1];
	return 0;
} 
