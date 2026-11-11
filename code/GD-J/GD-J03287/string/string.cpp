#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,ans=0,minus;
	cin>>n;
	char s[n];
	long long a[n],head=0,tail=n-1;
	for(long long i=0;i<n;i++){
		cin>>a[i]>>s[i];
	}
	while(head<tail){
		minus=min(a[head],a[tail]);
		if(s[head]!=s[tail]){
			ans+=minus;
		}
		a[head]-=minus;
		a[tail]-=minus;
		if(a[head]==0) head++;
		if(a[tail]==0) tail--;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
