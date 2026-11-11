#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=5e5+10;
int n,m,ans;
int a[N],p[N],cnt[N],b[N];
int answer[N];
int abs(int a,int b){
	if(a-b>=0) return a-b;
	return b-a;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	int mm=m,sum;
	for(int i=1; i<=n; i++)
		cin>>a[i];
	for(int i=2; i<=n; i++)
		p[i]=a[i]-a[i-1];
	//特殊性质 
	int ts=3;
	for(int i=2; i<=n; i++)
		if(p[i]!=p[2]) ts=0;//不是等差 
	if(ts==3 && p[2]==1) ts=1;//A
	else if(ts==3 && p[2]!=1) ts=2;//B
	//count:代价 
	//ai均为正 
	if(ts==1){
		for(int i=1; i<=n; i++){
			int count=(i*(i-1))/2;
			if(count<=m) ans++;
		}
		cout<<ans;
		return 0;
	}
	//ai可能为负 
	else if(ts==2){
		for(int i=1; i<=n; i++){
			int count=p[2]*((i*(i-1))/2);
			if(count<=m) ans++;
		}
		cout<<ans;
		return 0;
	}
	if(n<=430){
		for(int i=1; i<=n; i++){
			for(int j=1; j<=n; j++) cnt[j]=0;
			for(int j=1; j<=n; j++){
				if(i==j) continue;
				if(a[i]>=a[j])
					cnt[j]=a[i]-a[j];
				else cnt[j]=10000000;//只能增不能减 
			}
			sort(cnt+1,cnt+n+1);
			/*
			for(int j=1; j<=n; j++)
				cout<<cnt[j]<<" ";
			cout<<endl;
			*/
			mm=m;
			for(int j=1; j<=n; j++){
				if(mm-cnt[j]>=0){
					answer[i]++;
					mm-=cnt[j];
				}
				else break;
			}
			//cout<<endl;
		}
		int maxn=0;
		for(int i=1; i<=n; i++)
			maxn=max(maxn,answer[i]);
		cout<<maxn;
		return 0;
	}
	//平均数 
	for(int i=1; i<=n; i++)
		sum+=a[i];
	int pj=sum/n;
	int minn=1e9;
	int num;
	for(int i=1; i<=n; i++){
		if(abs(a[i],pj)<minn){
			minn=abs(a[i],pj);
			num=i;
		}
	}
	for(int i=1; i<=n; i++)
		b[i]=abs(a[i],a[num]);
	sort(b+1,b+n+1);
	ans=0,mm=m;
	for(int i=1; i<=n; i++)
		if(mm-b[i]>=0){
			ans++;
			mm-=b[i];
		}
	/*
	cout<<endl;
	cout<<pj<<" "<<a[num]<<endl;
	for(int i=1; i<=n; i++)
		cout<<b[i]<<" ";
	cout<<endl;
	*/
	cout<<ans;	
	return 0;
}
