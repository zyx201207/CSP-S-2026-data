#include<bits/stdc++.h>
using namespace std;
const int N=5e5+100;
long long n,m,a[N],t[N];
bool chek(int p){
	long long v=0;
	for(int i=1;i<=p-t[p];i++){
		v=v+a[p]-a[i];
		if(v>m)return 0;
	}
	return 1;
}
int dfs(int p){
	t[p]=t[p-1]+1;
	if(p==n||a[p]!=a[p+1]){
		return t[p];
	}else{
		return t[p]=dfs(p+1);
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	long long x=0;
	bool f=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i==2)x=a[2]-a[1];
		if(i>1&&a[i]-a[i-1]!=x)f=0;
	} 
	if(f==1){
		if(x<0)x=-x;
		long long fx=0;
		for(int i=1;i<=n;i++){
			fx+=i*x;
			if(m<fx){
				cout<<i<<endl;
				return 0; 
			}
		}
		cout<<n<<endl;
		return 0;
	}else{
		sort(a+1,a+n+1);
		
		for(int i=1;i<=n;i++){
			t[i]=1;
			if(i<n&&a[i]==a[i+1])i+=dfs(i)-1;
			else if(i==n)t[i]=1;
		}
		//for(int i=1;i<=n;i++)cout<<t[i]<<" ";
		int l=1,r=n;
		while(l<r){
			int mid=(l+r+1)>>1;
			if(chek(mid)){
				l=mid;
			}else{
				r=mid-1;
			}
		}
		cout<<l<<endl;
	}
	return 0;
}
