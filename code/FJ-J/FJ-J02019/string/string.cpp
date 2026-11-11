#include<bits/stdc++.h>
using namespace std;
long long n,sum,cnt,ans;
long long a[200005],s[200005];
char ch[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>ch[i];
		sum+=a[i];
	}
	if(sum%2==1){
		for(int i=1;i<=n;i++){
			cnt+=a[i];
			if(cnt>=sum/2+1){
				cnt=0;
				sum--;
				a[i]--;
				break;
			}
		}
	}
	long long c=sum/2,d=sum/2+1,c1,d1;
	for(int i=1;i<=n;i++){
		cnt+=a[i];
		if(cnt>=c){
			c1=i;
		}
		if(cnt>=d){
			d1=i;
			break;
		}
	}
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	long long e=c-s[c1-1];
	long long f=s[d1]-d+1;
	while(c1>0&&d1<=n){
		if(e>f){
			if(ch[c1]!=ch[d1]){
				ans+=f;
			}
			d1++;
			e-=f;
			f=a[d1];
		}
		if(e==f){
			if(ch[c1]!=ch[d1]){
				ans+=f;
			}
			c1--;
			d1++;
			e=a[c1];
			f=a[d1];
		}
		if(e<f){
			if(ch[c1]!=ch[d1]){
				ans+=e;
			}
			c1--;
			f-=e;
			e=a[c1];
		}
	}
	cout<<ans;
	return 0;
}

