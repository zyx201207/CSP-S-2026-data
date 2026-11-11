#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n;
long long m;
long long a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
//	for(int i=1;i<=n;i++){
//		cout<<a[i]<<" ";
//	}
	long long ans=1,cnt=0;
	
	if(n<=5000){
		for(long long i=1;i<=n;i++){
			long long ans_=1;
			cnt=0;
			for(long long j=i;j<n;j++){
				int tmp=a[j+1]-a[j];
				if(cnt+tmp*(j-i+1)<=m){
					cnt+=tmp*(j-i+1);
					ans_++;
				}
				else{
					//cout<<endl<<a[j+1]<<" "<<ans_<<endl;
					break;
				}
			}
			ans=max(ans,ans_);	
		}
	}
	else{
		for(long long i=1;i<n;i++){
		int tmp=a[i+1]-a[i];
		//cout<<tmp<<endl;
		if(cnt+tmp*i<=m){
			cnt+=tmp*i;
			ans++;
		}
		else{
			//cout<<endl<<a[i]<<" "<<i<<endl;
			break;
		}
	}
	}

	cout<<ans<<'\n';
}
