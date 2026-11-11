#include<bits/stdc++.h>
using namespace std;
long long a[100005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long m;
	cin>>n>>m;
	bool sl=1;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i){
			sl=0;
		}
	}
	if(sl)
	{
		int ans=a[n];
		int m_1=m;
		int cnt=1;
		for(long long i=n-1;i>=1;i--){
			if(m_1>=(ans-a[i])){
				m_1-=ans-a[i];
				cnt++;
			}
			else{
				break;
			}
		}
		cout<<cnt;
		return 0;
	}
	else{
		sort(a+1,a+n+1);
		int ans=a[n];
		int m_1=m;
		int cnt=1;
		for(long long i=n-1;i>=1;i--){
			if(m_1>=(ans-a[i])){
				m_1-=ans-a[i];
				cnt++;
			}
			else{
				break;
			}
		}
		int xxx=(1+n)/2;
		int ans2=a[xxx];
		int m_12=m;
		int cnt2=0;
		for(long long i=1;i<=n;i++){
			if(m_12>=(ans2-a[i]) && (ans2-a[i])>=0){
				m_12-=ans2-a[i];
				cnt2++;
				//cout<<m_12<<ans2-a[i]<<endl;
			}
			else{
				break;
			}
		}
		//int xxx=(1+n)/2;
		int ans3=a[xxx];
		int m_13=m;
		int cnt3=1;
		for(long long i=xxx-1;i>=1;i--){
			if(m_13>=(ans3-a[i])){
				m_13-=ans3-a[i];
				cnt3++;
			}
			else{
				break;
			}
		}
		cout<<max(max(cnt,cnt2),cnt3);
		//cout<<cnt3;
	}
	return 0;
} 
