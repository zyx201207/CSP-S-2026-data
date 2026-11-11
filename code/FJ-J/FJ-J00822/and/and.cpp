#include<bits/stdc++.h>
using namespace std;
#define int unsigned long long
const int N=2e5+5;
int n,m,a[N],t[N],tt[N],tcnt,Log2[35],Max=-1,cnt=0,k,sum=0;
bool cmp(int a,int b){
	return a>b;
} 
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	Log2[0]=1;
	for(int i=1;i<=31;i++)
		Log2[i]=Log2[i-1]*2;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i],t[++cnt]=a[i];
		Max=max(Max,a[i]);
	}
	k=upper_bound(Log2,Log2+31,Max)-Log2;
//	cout<<k<<endl;
	sort(t+1,t+1+n);
	for(int i=k;i>=0;i--){
		tcnt=0;
		for(int j=1;j<=cnt;j++)
			if(t[j]&(1<<i))tt[++tcnt]=t[j];
//		cout<<"~"<<i<<"\n";
//		for(int i=1;i<=tcnt;i++)
//			cout<<tt[i]<<" ";
//		cout<<endl;
		if(tcnt>=m){
			sum+=1<<i;
			for(int j=1;j<=tcnt;j++)t[j]=tt[j];
			cnt=tcnt;
		}
	}
	cout<<sum<<endl;
	return 0;
} 
