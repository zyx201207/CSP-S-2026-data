#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n;
int a[N];
char c[N];
int cnt=0;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		cnt+=a[i];
	}
	//bool f=0;
	//if(cnt%2==1) f=1;
	//else f=0;
	cnt/=2;
	int l=1,r=n,ans=0,fcnt=0,ecnt=0;
	while(fcnt<cnt){
		if(fcnt+a[l]<=cnt) fcnt+=a[l],ecnt=a[l];
		else ecnt=cnt-fcnt,fcnt=cnt;
		//cout<<"ecnt"<<ecnt<<endl;
		while(ecnt>0){
			if(a[r]<=0) r--;
			if(c[l]!=c[r]){
				if(ecnt>=a[r]) ecnt-=a[r],ans+=a[r],a[r]=0;
				else a[r]-=ecnt,ans+=ecnt,ecnt=0;
				//cout<<"l"<<l<<" "<<"r"<<r<<" "<<"fcnt"<<fcnt<<" "<<"ecnt"<<ecnt<<endl;
			}else{
				if(ecnt>a[r]) ecnt-=a[r],a[r]=0;
				else a[r]-=ecnt,ecnt=0;
			}
			 
		}
		l++;
	}
	cout<<ans<<endl;
	return 0;
}

