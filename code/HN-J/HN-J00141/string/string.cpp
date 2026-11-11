#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[200100],b[200100];
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	deque<pair<int,int>>fq;
	deque<pair<int,int>>bq;
	int l=0;
	for(int i=1;i<=n;i++){
		char c;
		cin>>a[i]>>c;
		b[i]=c-'a';
		l+=a[i];
	}
	int fqs=0;
	int bqs=0;
	for(int i=1;i<=n;i++){
		if(fqs+a[i]<=l/2){
			fq.push_back({a[i],b[i]});
			fqs+=a[i];
		}
		else if(fqs!=l/2&&fqs+a[i]>l/2){
			if(l%2==0){
				fq.push_back({l/2-fqs,b[i]});
				bq.push_front({a[i]+fqs-l/2,b[i]});
				fqs+=l/2-fqs;
				bqs+=a[i]+fqs-l/2;
			}else {
				fq.push_back({l/2-fqs,b[i]});
				if(a[i]+fqs-l/2-1>0)
					bq.push_front({a[i]+fqs-l/2-1,b[i]});
				fqs+=l/2-fqs;
				bqs+=a[i]+fqs-l/2-1;
			}
		}else {
			bq.push_front({a[i],b[i]});
			bqs+=a[i];
		}
	}
	int ans=0; 
	while(!fq.empty()){
		int a1=fq.front().first;
		int b1=fq.front().second;
		int a2=bq.front().first;
		int b2=bq.front().second;
		fq.pop_front();
		bq.pop_front();
		if(a1==a2){
			if(b1!=b2)ans+=a1;
		}else if(a1<a2){
			if(b1!=b2)ans+=a1;
			bq.push_front({a2-a1,b2});
		}else{
			if(b1!=b2)ans+=a2;
			fq.push_front({a1-a2,b1});
		}
	}
	cout<<ans;
	return 0;
}

