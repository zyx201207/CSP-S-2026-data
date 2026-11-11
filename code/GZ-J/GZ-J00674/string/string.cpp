//GZ-J00674兴义市弘毅中学龙家仁
#include<bits/stdc++.h>
using namespace std;
long long n,a[500005],ans=0,cnt,m=1,sum,k=1,l=1;
string s,c,cc,ss;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n;
	if(n==1){
		cout<<ans;
		return 0;
	}
	while(n--){
		cin>>a[cnt]>>s;
		ss+=s;
		if(cnt!=0&&s[cnt]!=s[cnt-1]) k=0;
		if(cnt!=0&&a[cnt]!=a[cnt-1]){
			m=0;
		}
		cnt++;
		sum+=a[cnt-1];
		if(a[cnt-1]>=1000000000) l=1000000000;
		a[cnt-1]=a[cnt-1]%1000000000+1;
		while(a[cnt-1]--){
			c+=s;
		}
		
	}
	if(k) {
		cout<<ans;
		return 0;
	}
	cc=c;
	reverse(c.begin(),c.end());
	if(cc==c) {
		cout<<ans;
		return 0;
	}
	if(m&&n%2==0){
		for(long long i = 0;i<n/2;i++){
			if(ss[n-i-1]!=cc[i]){
				ans++;
			}	
		}
		cout<<ans*a[1]*l;
		return 0;
	}else if(n%2==1&&m){
		for(long long i = 0;i<n/2+1;i++){
			if(ss[n-i-1]!=ss[i]){
				ans++;
			}	
		}
		cout<<ans*a[1]*l;
		return 0;
	}
	if(sum%2==0&&!m){
		for(long long i = 0;i<sum/2;i++){
			if(c[sum-i-1]!=c[i]){
				ans++;
			}	
		}
	}else{
		for(long long i = 0;i<sum/2+1;i++){
			if(c[sum-i-1]!=c[i]){
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
} 
