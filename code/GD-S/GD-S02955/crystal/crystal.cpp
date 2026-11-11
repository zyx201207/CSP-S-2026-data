#include <bits/stdc++.h>
using namespace std;
const int N=500005;
const int M=1000000000,M2=100000000;
int n,a[N],minp[N],minpp[N];
long long m;
bool check(int k){
	for(int j=k;j<=n;j++){
		int i=j-k+1;//i j
		int tmp=minpp[j]-minpp[i]-(a[j]-a[i])*(i-1);
		if(tmp<=m) return 1;
	}
	return 0;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	if((n<=5000 and m<=M)or(n<=N and m<=M2)){
		//cout<<"y"<<endl;
		//二分
		for(int i=1;i<=n;i++) cin>>a[i];
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++) minp[i]=a[i]-a[i-1];
		for(int i=1;i<=n;i++) minpp[i]=minpp[i-1]+(a[i]-a[i-1])*(i-1);
		//for(int i=1;i<=n;i++) cout<<a[i]<<" ";
		//cout<<endl;
		int l=0,r=n+1;
		//保证l可行 r不可行
		while(l+1!=r){
			int mid=(l+r)/2;
			if(check(mid)==1) l=mid;
			else r=mid; 
		} 
		cout<<l;
		return 0;
	}
	if(n<=N and m>M2){
		bool ty1=1,ty2=1;
		long long t1,t2;
		cin>>t1>>t2;
		int gap=t2-t1;
		for(int i=3;i<=n;i++){
			t1=t2;
			cin>>t2;
			if(t2-t1!=1) ty1=0;
			if(t2-t1!=gap) ty2=0;
		}
		if(ty1==1){
			int l=1,r=n;
			//保证l可行 r不可行
			while(l+1!=r){
				int mid=(l+r)/2;
				if((1+mid)*mid/2<=m) l=mid;
				else r=mid; 
			} 
			//cout<<"ty1"<<endl;
			cout<<l+1;
			return 0;
		}
		else if(ty2==1){
			int l=1,r=n;
			//保证l可行 r不可行
			while(l+1!=r){
				int mid=(l+r)/2;
				if((1+mid)*mid/2*gap<=m) l=mid;
				else r=mid; 
			} 
			//cout<<"ty2"<<endl;
			cout<<l+1;
			return 0;
		}
	}
}
