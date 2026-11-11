#include <bits/stdc++.h>
using namespace std;
long long n,sum=0,ans=0;
struct Po{
	char c;
	long long f;
	Po(char c_=0,long long f_=0){
		f=f_;
		c=c_;
	}
}a[200000+10];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i].f >> a[i].c;
		sum+=a[i].f;
	}
	if(sum%2!=0){
		long long h=0;
		for(int i=1;i<=n;i++){
			if(h+a[i].f>=(sum+1)/2){
				a[i].f--;
				break;
			}
			h+=a[i].f;
		}
		sum--;
	}
	long long l=1,r=n,fl=0,fr=0;
	while(l<=r){
		if(l==r){
			break;
		}
		if(a[l].c!=a[r].c){
			ans+=min(abs(a[l].f-fl),abs(a[r].f-fr));
			long long kl=fl,kr=fr;
			kl+=min(abs(a[l].f-fl),abs(a[r].f-fr));
			kr+=min(abs(a[l].f-fl),abs(a[r].f-fr));
			fl=kl,fr=kr;
		}else{
			long long kl=fl,kr=fr;
			kl+=min(abs(a[l].f-fl),abs(a[r].f-fr));
			kr+=min(abs(a[l].f-fl),abs(a[r].f-fr));
			fl=kl,fr=kr;
		}
		if(fl==a[l].f)l++,fl=0;
		if(fr==a[r].f)r--,fr=0;
	}
	cout << ans;
	return 0;
}
