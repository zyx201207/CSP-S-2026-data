#include<bits/stdc++.h>
using namespace std;
long long a[105000]={};
int n;
long long mm;
bool ck(){
	long long p=a[n]-a[n-1];
	for(int i=1;i<n;i++){
		if(p!=(a[i+1]-a[i])) return false;
	}
	return true;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>mm;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	long long ans=0;
	long long j;
	long long d,k;
	if(!ck()){
		for(int i=n;i>=1;i--){
			long long cnt=0;
			j=a[i];
			k=i;
			long long m=mm;
			while(m>0&&k>=1){
				k--;
				if(k==0) continue;
				d=j-a[k];
				if(m>=d){
					m-=d;
					cnt++;
				}else{
					break;
				}
			}
			++cnt;
			ans=max(ans,cnt);
	    }
		cout<<ans;
	}
	else{
		long long ccc=1;
		long long ccccc=a[n]-a[n-1];
		long long cc;
		for(int i=1;i<n;i++){
			cc=(i*ccccc);
			if(mm>=cc){
				mm-=cc;
				ccc++;
			}else break;
		}
		cout<<ccc;
	}
	
	return 0;
} 

