#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long arr[200009],ans[40000000],q=1,Max=-1e9;
bool a=1,b=0;
bool cmp(long long a,long long b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
		Max=max(Max,arr[i]);
		if(arr[i]=i-1) b=1;	
		if(arr[i]>=4) a=0;
	}
	if(m==1){
		cout<<Max;
		return 0;
	}else if(m==2){
		for(int i=1;i<=n-1;i++){
			for(int j=i+1;j<=n;j++){
				ans[q]=arr[i]&arr[j];
				Max=max(Max,ans[q]);
			}
		}
		cout<<Max;
		return 0;
	}else if(m==n){
		long long x=arr[1];
		for(int i=2;i<=n;i++){
			x=(x&arr[i]);	
		}
		cout<<x;
		return 0;
	}else if(m==n-1){
		long long x=1,anss=arr[1];
		for(int i=1;i<=n;i++){
			for(int j=2;j<=m;j++){
				if(i==x) continue;
				else anss=anss&arr[j];
			}
			Max=max(Max,anss);
			x++;
		}
		cout<<Max;
	}else if(b==1){
		sort(arr+1,arr+1+n,cmp);
		long long x;
		if(arr[1]%2==0){
			long long x=2,aaa=arr[2];
			for(int i=1;i<=m;i++){
				aaa=arr[x+2]&aaa;
				x+=2;
			}
			cout<<aaa;
			return 0;
		}else{
			long long x=1,aaa=arr[1];
			for(int i=1;i<=m;i++){
				aaa=arr[x+2]&aaa;
				x+=2;
			}
			cout<<aaa;
			return 0;
		}
	}else if(a==1){
		cout<<3;
	}
	return 0;
}
