//这个T2怎么这么囊啊
//T3一眼题
//不是我T3都过完了怎么T2还没思路啊
#include<bits/stdc++.h>
using namespace std;
long long gcd(long long a,long long b){
	return a==0?gcd(b,a%b):b;
}
long long n,a[114514],tp,s[114514],sum;
char c[114514];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1,x;i<=n;i++){
		cin>>a[i]>>c[i];
		tp=(i==1?a[i]:gcd(tp,a[i]));
	}
	tp=gcd(tp,a[n]);
	for(long long i=1;i<=n;i++){
		a[i]/=tp;
	}
	long long mk=1;
	for(long long i=1;i<=n;i++){
		if(c[i]==c[i-1]){
			a[mk]+=a[i];
			a[i]=0;
		}
		else{
			mk=i;
		}
	}
	long long cnt=1;
	for(long long i=2;i<=n;i++){
		if(a[i]==0){
			c[i]=0;
		}
		else {
			a[++cnt]=a[i];
			c[cnt]=c[i];
			if(cnt!=i)a[i]=0,c[i]=0;
		}
	}
	n=cnt;
	long long tot=1;
	tot*=tp;
	tp=1;
	for(long long i=1;i<=n;i++){
		tp=(i==1?a[i]:gcd(tp,a[i]));
	}
	for(long long i=1;i<=n;i++){
		a[i]/=tp;
	//	cout<<a[i]<<" ";
	}
	//cout<<endl;
	for(long long i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	if(s[n]==1||s[n]==0){
		cout<<0;
		return 0;
	}
	//for(long long i=1;i<=n+1;i++){
	//	cout<<a[i]<<" ";
	//}
	//cout<<endl;
	long long d=lower_bound(s+1,s+1+n,s[n]/2)-s;
	//cout<<"d="<<d<<endl;
	//cout<<s[d]<<" "<<s[n]-s[d]<<endl;
	if(s[n]%2==0&&s[d]!=s[n]-s[d]){
		for(long long i=n;i>d;i--){
			a[i+1]=a[i];
			c[i+1]=c[i];
		}
		a[d+1]=(s[n]/2-s[d-1]);
		a[d]-=a[d+1];
		swap(a[d],a[d+1]);
		n++;
	}
	else if(s[n]%2!=0&&s[d]!=s[n]-s[d]){
		for(long long i=n;i>d;i--){
			a[i+2]=a[i];
			c[i+2]=c[i];
		}
		a[d]--;
		a[d+1]=1;
		long long y=a[d];
		a[d]=s[n]/2-s[d-1];
		a[d+2]=y-a[d];
		c[d+1]=c[d],c[d+2]=c[d];
		n+=2;
	}
	//10:37快打完了。。。 
	//for(long long i=1;i<=n+2;i++){
	//	cout<<a[i]<<" "<<c[i]<<endl;
	//}
	long long mid=s[n]/2,l1=0,l2=0;
	long long ans=0;
	for(long long i=1;i<=n/2;){
		if(c[i]!=c[n+i-1]){
			ans+=abs(a[i]-a[n-i+1]);
			i++;
		}
		//else{
			i+=min(a[i],a[n-i+1]);
		//	ans+=min(a[i],a[n-i+1]);
		//}
		if(i==n/2)break;
	}
	//cout<<ans<<" "<<tot<<" "<<tp<<endl;
	cout<<max(ans,1ll)*tot*tp;
	//11:04这里面。。。是地狱啊。。。 
}
/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/
