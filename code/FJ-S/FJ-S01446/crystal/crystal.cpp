#include<bits/stdc++.h>
using namespace std;
long long const N=1e3;
int main (){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,a[N],cnt=0;
	cin>>n>>m;
	int k=m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		if(k>0){
			if(a[i]+1==a[i+1]){
				cnt++;
				k--;
			}else{
				a[i]+=1; 
				k--;
			}
		}
	}
	if(cnt>=1) cout<<cnt+1;
	else cout<<cnt;
	return 0;
}
