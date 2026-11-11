#include<bits/stdc++.h>
using namespace std;
long long ri(){
	long long ans=0;
	char c=getchar();
	for(;!isdigit(c);c=getchar()){}
	for(;isdigit(c);c=getchar())	ans=ans*10+(c^48);
	return ans;
}
long long a[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n=ri(),m=ri();
	for(long long i=1;i<=n;i++)	a[i]=ri();
	sort(a+1,a+1+n);
	queue<long long> b;
	long long sum=0,num=1,j=1,ans=-1;
	b.push(a[1]);
	for(int i=2;i<=n;i++){
		long long x=a[i]-a[i-1];
		sum+=1LL*(i-j)*x;
		//cout<<i<<" "<<sum<<endl;
		while(!b.empty()&&sum>m){
			sum-=a[i]-b.front();
			j++;
			b.pop();
			num--;
		}
		if(a[i]-a[i-1]<=m)	b.push(a[i]);
		if(sum<=m)	num++;
		ans=max(ans,num);
		//cout<<sum<<" "<<ans<<'\n';
	}
	cout<<ans;
	return 0;
}
/*
�Բ⣺ 
5 2
111 122 211 113 0
*/
