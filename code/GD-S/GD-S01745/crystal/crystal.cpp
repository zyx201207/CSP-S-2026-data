#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,maxn=0,sum=0;
	cin>>n>>m;
	vector<long long>s(n);
	vector<long long>q(n);
	for(long long i=0;i<n;i++)cin>>s[i];
	sort(s.begin(),s.end());
	q[0]=0;
	for(long long i=1;i<n;i++){
		long long a=s[i];
		q[i]=(s[i]-s[i-1])*i+q[i-1];
		if(q[i]<=m){
			for(long long j=i;j<n;j++)
				if(s[j]==a)sum++;
			maxn=i+sum;
			sum=0;
		}
		else if(q[i]>m)break; 
	}
	cout<<maxn;
	return 0;
}
