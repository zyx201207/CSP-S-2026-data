#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
long long n,m;
long long a[555555],dif[555555],ref,ans,modif[555555];
//void dfs()
bool therf_i=1,aq=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(a[i]-a[i-1]!=1)therf_i=0;
		if(i>3){if(a[i]-a[i-1]!=a[i-1]-a[i-2])aq=0;}
	}
	if(therf_i){
		long long rf=1,bk=0,cur=1;
		for(int i=1;i<=n;i++){
			
			bk+=cur;
			if(bk>m)break;
			cur++;
			rf++;
		}
		cout<<min(rf,n);
		return 0;
	}
	if(aq){
		long long rf=1,bk=0,cur=a[n]-a[n-1],re=a[n]-a[n-1];
		for(int i=1;i<=n;i++){
			
			bk+=cur;
			if(bk>m)break;
			cur+=re;
			rf++;
		}
		cout<<min(rf,n);
		return 0;
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		dif[i]=a[i]-a[i-1];
	}
//	sort(dif+1,dif+n+1);
	for(int i=1;i<n;i++){
		long long cs=1,lower_m=0,pos=i+1;
		while(cs+i<=n){
			
			lower_m+=(a[pos]-a[pos-1])*cs;
//			cout<<"lower_m:"<<lower_m<<" result:"<<cs<<" first:"<<i<<" pos:"<<pos<<" now_ans:"<<ans<<"---->next_need:";
//			cout<<(a[pos]-a[pos-1])*cs<<"\n";
			if(lower_m>m){
//				cout<<"Nowed\n";
			break;	
			}
			cs++;
			pos++;
			
		}
//		cout<<"next\n";
		ans=max(cs,ans);
	}
	
	cout<<ans;
	return 0;
}
