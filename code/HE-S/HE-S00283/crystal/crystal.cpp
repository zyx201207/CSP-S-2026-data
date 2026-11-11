#include <iostream>
#include <algorithm>
#define MAXN 500009
using namespace std;
int n,ans;
long long m,a[MAXN],pre[MAXN],maxa,cnt,minp,cha;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	bool bora=true;
	bool b=true;
	for(int i=0;i<n;i++){
		cin >> a[i];
		if(i>0&&b){
			cha=a[i]-a[i-1];
			b=false;
		}
		if(i>0&&a[i]-a[i-1]!=cha) bora=false;
		maxa=max(maxa,a[i]);
		pre[i]=1;
	}
	sort(a,a+n);
	if(bora){
		pre[n-1]=0;
		for(int i=0;i<n-1;i++) pre[n-1]+=(maxa-a[i]);
	    for(int i=n-2;i>=0;i--) pre[i]=pre[i+1]-(a[i+1]-a[i])*(i+1);
	    for(int i=0;i<n;i++){
		    if(pre[i]>m){
			    cout << i;
		    	return 0;
		    }
		    ans=i;
	    }
	    cout << ans+1;
	    return 0;
	}
	for(int i=0;i<n;i++){
		int k=i;
		cnt=m;
		while(--k>=0){
			if(a[i]-a[k]>cnt){
				break;
			}
			pre[i]++;
			cnt-=a[i]-a[k];
		}
	}
	for(int i=0;i<n;i++){
		minp=max(minp,pre[i]);
	}
	cout << minp;
	return 0;
}
