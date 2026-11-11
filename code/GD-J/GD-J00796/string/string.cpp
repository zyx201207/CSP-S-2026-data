#include<bits/stdc++.h>
using namespace std;
long long a[200010];
char b[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio();
	cin.tie(0);
	int n;
	cin>>n;
	long long ans=0,sum=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		sum+=a[i];
	}
	long long mid=sum/2,end=n,o=0;
	for(int head=1;head<=n;head++){//±éÀúÇ°°ë¶Î 
		if(head==end) break;
		o+=a[head];
		if(o>mid){
			a[head]-=(o-mid);
		}
		long long t=a[head];
		while(t>0){
			if(a[end]<=t) {
				if(b[end]!=b[head]) ans+=a[end];
				t-=a[end],end--;
			}
			else{
				if(b[end]!=b[head]) ans+=t;
				a[end]-=t,t=0;
			}
		}
	}
	cout<<ans;
	return 0;
} 
