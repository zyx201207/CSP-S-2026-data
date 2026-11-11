#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=5e5+10;
int a[MAXN],lzy[MAXN];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ll n,m;
	cin>>n>>m;
	bool op=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i>1){
			if(a[i]-a[i-1]!=a[2]-a[1]) op=1;
		}
    }
    if(op==0){
    	int cntpty=1;
    	for(int i=n;i>1;i--){
    		if(m>=abs(a[n]-a[i-1])){
    			m-=abs(a[n]-a[i-1]);
    			cntpty++;
			}
			else{
				break;
			}
		}
		cout<<cntpty;
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++){
		lzy[i]=a[n]-a[i-1];
	}
	if(m==0){
		cout<<1;
		return 0;
	}
	ll cntans=0;
	ll cnt=1;
	for(int i=2;i<=n;i++){
		cnt=1;
		int m1=m;
		for(int j=i-1;j>=0;j--){
			if(abs(a[i]-a[j])>m1){
				break;
			}
			else{
				cnt++;
				m1-=abs(a[i]-a[j]);
			}
		}
		if(cnt>cntans) cntans=cnt;
	}
	cout<<cntans;
	return 0;
}
