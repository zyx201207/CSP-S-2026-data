#include<bits/stdc++.h>
using namespace std;
long long n,m,a[100005],ans=1,ansm=0,dcomb=0;
long long maxx(long long a,long long b){
	if(a>b) return a;
	else return b;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		dcomb=0;
	  for(int j=i-1;j>0;j--){
	  	dcomb+=a[i]-a[j];
	  	if(m>=dcomb) ans++;
	  	if(m<dcomb){
		  ansm=maxx(ans,ansm);ans=1;break;
		}
	  }
	  ansm=maxx(ans,ansm);ans=1;
}
	  cout<<ansm<<endl;
	  return 0;
}
