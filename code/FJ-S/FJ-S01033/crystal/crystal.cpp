#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,ans;
long long m;
long long a[N];
void f(int k){
	int l=k-1,num=0;
	long long t=m,le;
	while(1){
		le=a[k]-a[l];
		if(l>=1 && t>=le){
			num++;
			l--;
			t-=le;
		}else{
			break;
		}
	}
	ans=max(num,ans);
	return ;
	
}
bool cmp(long long a,long long b){
	return a<b;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
		for(int i=n;i>=ans+1;i--) f(i);
		cout<<ans+1;

	return 0;
} 
