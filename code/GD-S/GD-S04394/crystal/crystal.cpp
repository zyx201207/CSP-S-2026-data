#include<bits/stdc++.h>
using namespace std;
long long num,k;
long long val[500005];
long long ans[500005];
long long sm[500005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>num>>k;
	for(long long i=1;i<=num;i++){
		cin>>val[i];
	}
	sort(val+1,val+num+1);
	long long cnt=0,flag=1;
	long long rmx=1;
	for(int i=1;i<=num;i++){
		while(flag&&rmx<=num){
			if(cnt+(val[rmx]-val[rmx-1])*(rmx-i)<=k){
				cnt+=(val[rmx]-val[rmx-1])*(rmx-i);
				rmx++;
			}
			else{
				flag=0;
			}
		}
		flag=1;
		ans[i]=rmx-i;
		cnt-=(val[rmx-1]-val[i]);
	}
	long long mx=-1,mxpos=0;
	for(int i=1;i<=num;i++){
		mx=max(mx,ans[i]);
	}
	cout<<mx;
	return 0;
}
