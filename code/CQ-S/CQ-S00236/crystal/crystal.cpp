#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+1;
long long m;
int n;
long long a[maxn];
long long pre[maxn];
long long ans;
bool check(long long mid){
	long long min1=INT_MAX;
	long long he=0;
	for(int i=n;i>=mid;i--){
		he=(mid*a[i]-pre[i]+pre[i-mid]);
		min1=min(he,min1);
	}
	//cout<<min1<<" "<<m<<endl;
	if(min1>m)return false;
	else return true;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	pre[0]=0;
	for(int i=1;i<=n;i++){
		pre[i]=pre[i-1]+a[i];
	}
	long long L=1,R=n;
	long long mid=0;
	while(L<R){
	    mid=(L+R)>>1; 
	    if(check(mid)){
	    	L=mid+1;
	    }else{
	    	R=mid-1;
		}
	} 
	if(check(mid+1)){
		cout<<mid+1;
	}else if(check(mid)){
		cout<<mid;
	}else if(check(mid-1)){
		cout<<mid-1;
	}
	return 0;
} 
