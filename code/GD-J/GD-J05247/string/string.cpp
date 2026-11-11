#include<bits/stdc++.h>
using namespace std;
long long n,a[10000001],flag=1,sum,maxx=0,minn=LONG_LONG_MAX;
char a1[10000001],k;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
		maxx=max(a[i],maxx);
		minn=min(a[i],minn);
		cin>>a1[i];
	}
	k=a1[1];
	for(long long i=1;i<=n;i++){
		if(a1[i]!=k){ 
			flag=0;
			break;
		} 
	}
	if(flag==1){
		cout<<0;
	}
	else if(n==2){
		cout<<minn;
	}
	else{
		cout<<sum-maxx-minn;
	}
	return 0;
}
