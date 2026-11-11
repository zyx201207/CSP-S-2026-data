#include<bits/stdc++.h>
using namespace std;
string s1;
struct node{
	long long s;
	char m;
}a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	long long sum=0;
	for(int i=1;i<=n;i++){
		long long x;
		char c;
		cin>>x>>c;
		sum+=x;
		a[i].s=x;
		a[i].m=c;
	}
	long long t=0;
	for(int i=1;i<=n;i++){
		while(a[i].s--){
			s1[t++]=a[i].m;
		}
	}
	long long ans=0;
	for(int i=0;i<(sum-1)/2;i++){
		if(s1[i]!=s1[(sum-1)-i])ans++;
	}
	cout<<ans<<endl;
	return 0;
}
