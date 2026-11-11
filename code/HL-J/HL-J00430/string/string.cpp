#include<bits/stdc++.h>
using namespace std;
struct st{
	int a;
	char s;
}a[200005];
st d[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
    	cin>>a[i].a>>a[i].s ;
	}
	for(int i=0;i<n;i++){
		d[n-i].s=a[i+1].s;
		d[n-i].a =a[i+1].a;
	}
	long long ans=0;
	int y=0;
	for(int i=1;i<=n;i++){
		if(a[i].s!=d[i].s&&a[i].a==d[i].a){
			ans+=d[i].a;
			y++;
		}else if(a[i].s==d[i].s&&a[i].a!=d[i].a){
			if(a[i].a >d[i].a){
				ans+=a[i].a-d[i].a;
			}else{
				ans+=d[i].a-a[i].a;
			}
		}else if(a[i].s!=d[i].s&&a[i].a!=d[i].a){
			if(a[i].a >d[i].a){
				ans+=d[i].a;
			}else{
				ans+=a[i].a;
			}
		}

	}
	cout<<ans/2;
    return 0;
}
