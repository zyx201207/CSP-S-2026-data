#include <bits/stdc++.h>
long long n,m,a[500005],min1=10000000,max1=-1000000,b[1000005],ans,cnt,w=-100;
using namespace std;
bool cmp(long long x,long long y){
	return x<y;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    cin>>n>>m;
    
    for(int i=1;i<=n;i++){
    	cin>>a[i];
    	max1=max(max1,a[i]);
    	min1=min(min1,a[i]);
	}
	sort(a+1,a+1+n,cmp);
	if(n>5005){
		for(int i=n;i>=1;i--){
			m-=a[n]-a[i];
			if(m<a[n]-a[i]){
				break;
			}
			else{
				cnt++;
			}
		}
		cout<<cnt;
		return 0;
	}
	for(int j=n;j>=1;j--){
		ans=0;
		cnt=0;
		for(int i=j;i>=1;i--){
			ans+=a[j]-a[i];
			if(m<ans){
				break;
			}
			else{
				cnt++;
			}
		}
		w=max(cnt,w);
	}
	cout<<w;
	
	return 0;
}
