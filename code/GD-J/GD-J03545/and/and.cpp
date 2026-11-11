#include <bits/stdc++.h>
using namespace std;
const int N=2e5;
bool if1=1,if2=1;
int to2[35]={1,3,7,15,31,63,127,255,511,1023,2047,4095,8191,16383,32767,65535,131071,262143,524287,1048575,2097151,4194303,8388607,16777215,33554431,67108863,134217727,268435455,536870911,1073741823,2147483647};
long long a[N],n,m;
long long v=0;
void solve(int i,long long ans,int choice,bool r){
	if(n-i+1+choice<m)return;
	if(choice==m){
		v=max(v,ans);
//		cout<<"Arrive\n";
		return;
	} 
	if(r){
		if(choice==0){
			ans=a[i];
			choice++;
		}
		else{
			ans=ans&a[i];
			choice++;
		}
	}
//	cout<<ans<<" "<<a[i]<<" "<<choice<<"\n";
	solve(++i,ans,choice,1);
	solve(++i,ans,choice,0);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		for(int j=0;j<31;j++){
			if(a[i]+1==to2[j]){
				if1=1;
				break;
			}
			if1=0;
		}
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			v=max(v,a[i]);
		}
		cout<<v;
	}
	else if(m==2){
		for(long long i=1;i<=n;i++){
			for(long long j=i+1;j<=n;j++){
				v=max(v,i&j);
			}
		}
		cout<<v;
	}
	else if(m==n){
		for(int i=1;i<=n;i++){
			if(i==1)v=a[i];
			v&=a[i];
		}
		cout<<v;
	}
	else if(n<=20){
		solve(1,0,0,1);
		solve(1,0,0,0);
		cout<<v;
	}
	else if(m==n-1){
		
	}
	else if(if1){
		for(int i=1;i<=n;i++)v=min(v,a[i]);
		cout<<v;
	}
	else if(if2){
		
	}
	return 0;
}

