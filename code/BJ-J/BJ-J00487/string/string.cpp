#include<bits/stdc++.h>
using namespace std;
#define int long long
int a1[200100];char c1[200100];
int a2[200100];char c2[200100];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,len=0,sum=0;scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld %c",&a1[i],&c1[i]);
		a2[n+1-i]=a1[i];c2[n+1-i]=c1[i];
		len+=a1[i];
	}len/=2;
	int cnt=0,t=0;
	for(int i=1;i<=n;i++){
		if(!t){
			cnt+=a1[i];
			if(cnt>=len){
				a1[i]-=(cnt-len);
				t=1;
			}
		}else{
			a1[i]=0;c1[i]=0;
		}
	}
	cnt=0;t=0;for(int i=1;i<=n;i++){
		if(!t){
			cnt+=a2[i];
			if(cnt>=len){
				a2[i]-=(cnt-len);
				t=1;
			}
		}else{
			a2[i]=0;c2[i]=0;
		}
	}int i1=1,i2=1;
	cnt=0;while(cnt<len){
		if(a1[i1]<a2[i2]){
			a2[i2]-=a1[i1];
			if(c1[i1]!=c2[i2])sum+=a1[i1];
			i1++;cnt+=a1[i1];
		}if(a1[i1]>a2[i2]){
			a1[i1]-=a2[i2];
			if(c1[i1]!=c2[i2])sum+=a2[i2];
			i2++;cnt+=a2[i2];
		}if(a1[i1]==a2[i2]){
			if(c1[i1]!=c2[i2])sum+=a1[i1];
			i1++;i2++;cnt+=a1[i1];
		}
	}cout<<sum;
	return 0;
}
