#include<bits/stdc++.h>
using namespace std;
const int N=500005;
long long n,m;
long long a[N],dis[N];
long long sum[N];
/*inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-'){
			f=-1;
		}
		ch=getchar();
	}
	while(isdigit(ch)){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return x*f; 
}*/
int main(){
	//ios::sync_with_stdio(0);
	//cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	long long ans=0;
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++){
		dis[i]=a[i]-a[i-1];
	}
	//sort(dis+2,dis+1+n);
	for(int i=2;i<=n;i++){
		sum[i]+=dis[i]*(i-1)+sum[i-1];
		if(sum[i]>m){
			cout<<i-1<<endl;
			return 0;
		}
	}
	cout<<n;
	return 0;
}
