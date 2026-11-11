#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ulp(i,a,b) for(int i=a;i<=b;i++)
#define dlp(i,a,b) for(int i=a;i>=b;i--)
#define pic pair<int,char>
deque<pic> q1,q2;
const int N=2e5+5;
int n,cnt,a[N];
char o[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	ulp(i,1,n){
		cin>>a[i];
		cin>>o[i];
		cnt+=a[i];
	}
	if(n==1){
		puts("0");
		return 0;
	}
	int mid=cnt>>1;
	int tot=0;
	ulp(i,1,n){
		if(tot+a[i]>=mid){
			q1.push_back({mid-tot,o[i]});
			break;
		}
		q1.push_back({a[i],o[i]});
		tot+=a[i];
	}
	tot=0;
	
	dlp(i,n,1){
		if(tot+a[i]>=mid){
			q2.push_back({mid-tot,o[i]});
			break;
		}
		q2.push_back({a[i],o[i]});
		tot+=a[i];
	}
//	cout<<q1.size()<<" "<<q2.size()<<"**\n";
	int ans=0;
	while(1){
		if(q1.empty()||q2.empty())break;
		pic fir=q1.front(),sec=q2.front();
		q1.pop_front(),q2.pop_front();
		int f=(fir.second==sec.second?0:1);
		if(fir.first<sec.first){
			q2.push_front({sec.first-fir.first,sec.second});
		}
		else if(fir.first>sec.first){
			q1.push_front({fir.first-sec.first,fir.second});
		}
		ans+=min(fir.first,sec.first)*f;
	}
	cout<<ans;
}

