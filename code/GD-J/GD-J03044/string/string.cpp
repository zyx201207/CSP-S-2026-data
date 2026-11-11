#include<bits/stdc++.h>

using namespace std;
long long a[200010];
char b[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long sum=0,ans=0;
	int n,q;
	cin>>n;
	q=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		sum+=a[i];
	}
	while(ans-a[q]<sum/2){
		q++;
	}
	cout<<"0";
	return 0;
}
