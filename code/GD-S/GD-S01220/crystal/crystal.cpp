#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,l,o,la,ans,a[500005],p;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	l=a[1];
	o=1;
	la=1;
	ans=1;
	for(int i=2;i<=n;i++){
		p=a[i]*o-l;
		if(p<=m){
			++o;
			l=l+a[i];
			ans=max(ans,o);
		}else{
			for(;la<i;la++){
				l-=a[la];
				o--;
				if(a[i]*o-l<=m){
					la++;
					break;
				}
			}if(la==i){
				l=a[la];
				o=1;
			}
			else{
				++o;
				l=l+a[i];
				ans=max(ans,o);
			}
		}
	}cout<<ans;
}  
