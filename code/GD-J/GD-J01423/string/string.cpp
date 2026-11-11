#include<bits/stdc++.h>

using namespace std;
const int N=200005;
char s[N];
long long l[N],sum[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	long long n,m=0,mid=0,ans=0;cin>>n;
	for(int i=1;i<=n;i++){
		cin>>l[i]>>s[i];
		m+=l[i];
		sum[i]=sum[i-1]+l[i];
	}
	if(m%2==1)mid=(m>>1)+1;
	else mid=m>>1; 
	//a1 s1 a2 s2      ...a_mid-sum[i-1]-1 s_mid-sum[i-1]-1
	//an sn a_n-1 s_n-1...a_sum[i]-mid 
	for(long long i=1,j=n,t1=0,t2=0;sum[i]<=mid&&sum[j]>=mid;){
		long long minn=min(l[i]-t1,l[j]-t2),ri=l[i]-t1,rj=l[j]-t2;
		if(s[i]!=s[j]){
			ans+=minn;	
		}
		if(ri>=rj){	
			t1+=minn;
		}else{
			t2+=minn;
		}
		if(t1==l[i]){
			i++;t1=0;	
		}
		if(t2==l[j]){
			j--;t2=0;	
		}
	}
	cout<<ans;
	return 0;
}
