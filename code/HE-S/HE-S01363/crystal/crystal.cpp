#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[500005],b[500005];
bool p=0;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,ans=0;
	cin>>n>>m;
	if(n<=5000){
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(a[i]>100) p=1;
		}
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++){
			int j=1,k=m,l=1;
			for(j=1;j<=i;j++){
				b[j]=a[i]-a[j];
			}
			sort(b+1,b+j);
			while(k-b[l]>=0&&l<j){
				k=k-b[l];
				l++;
			}
			ans=max(ans,l-1);
		}	
		cout<<ans;
		return 0;
	}else{
		int a1,a2;
		cin>>a1>>a2;
		int k=a2-a1,l=1;
		while(m-k>=0){
			m-=k;
			l++;
			k+=a[2]-a[1];
		}
		cout<<l;
	}
	
}
