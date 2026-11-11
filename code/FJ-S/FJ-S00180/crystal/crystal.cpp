#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,max=0;
	cin>>n>>m;
	long long a[n+1]={},ca[n]={};
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		ca[i]=a[i+1]-a[i];
	}
	ca[n]=0;
	sort(ca+1,ca+n+1);
	for(int i=1;;i++){
		if(m-ca[i]>0||m-ca[i]==0){
			m-=ca[i];
			max++;
		}else{
			break;
		}
	}
	cout<<max-1;
	return 0;
}
