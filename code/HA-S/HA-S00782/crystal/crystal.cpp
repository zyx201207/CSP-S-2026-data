#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
long long a[N],s[N];
long long n,m;
long long ans;
bool st1,st2;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	long long re;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i){
			st1=1;
		}
	}
	sort(a+1,a+1+n);
	re=a[2]-a[1];
	for(int i=2;i<=n;i++){
		if(a[i]-a[i-1]!=re){
			st2=1;
		}
	}
	if(st1&&st2){
		for(int i=1;i<n;i++){
		    s[i]=a[i+1]-a[i];
	    }
	    for(int i=1;i<n;i++){
		    long long t=0;
		    long long ha=0;
		    long long cnt=i;
		    long long y=1;
		    while(ha<m&&cnt>0){
			    t=t+s[cnt];
			    ha+=t;
			    cnt--;
			    y++;
		    }
		    ans=max(ans,y);
	    }
	    cout<<ans<<"\n";
	}
	if(!st1){
		long long cnt=0;
		long long t=0;
		for(int i=1;i<n,cnt<=m;i++){
			cnt+=i;
			t=i;
		}
		cout<<t<<"\n";
	}
	if(!st2&&st1){
		long long cnt=0;
		long long t=0;
		for(int i=1;i<n,cnt<=m;i++){
			cnt+=re*i;
			t=i;
		}
		cout<<t<<"\n";
	}
	return 0;
}

