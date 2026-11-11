#include <bits/stdc++.h>
using namespace std;
long long n,m;

bool cmp(long long a,long long b){
	return a<b;
}

int main() { 
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	vector<long long>a(n+1,0);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	long long sp=m,ans=-1;
	sort(a.begin(),a.end(),cmp);
	sp=m;long long cnt=1,nt;
	for(int i=1;i<n;i++){
		if(ans==-1){
			sp=m,cnt=1;
			for(int j=i+1;j<=n;j++){
				if(sp>=cnt*(a[j]-a[j-1])){
					sp-=cnt*(a[j]-a[j-1]);
					cnt++;
				}else{
					break;
				}
			}
		}else if(i+cnt-1<=n){
			sp+=(a[i+cnt-2]-a[i-1]),cnt--;
			for(int j=i+cnt;j<=n;j++){
				if(sp>=(cnt*(a[j]-a[j-1]))){
					sp-=cnt*(a[j]-a[j-1]);
					cnt++;
					if(cnt>j-i)cnt--;
				}else{
					break;
				}
			}
		}else{
			break;
		}
		
		if(cnt>ans)ans=cnt;
	}
	cout<<ans;
	return 0;
}
