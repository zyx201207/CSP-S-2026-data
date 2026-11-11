#include <bits/stdc++.h>
using namespace std;
int n,m;
const int N=2e5+5;
int a[N],cnt[N];

struct ma{
	int sl;
	int xb;
}sum[N];

int man(int num){
	int ans=0;
	while(num){
		if(num%2==1){
			ans++;
		}
		num/=2;
	}
	return ans;
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		sum[i].sl=man(a[i]);
		cnt[i]=man(a[i]);
		sum[i].xb=i;
	}
	sort(cnt,cnt+n);
	int ans=0,fre;
	for(int i=n-1;i>=n-m;i--){
		for(int j=0;j<n;j++){
			if(sum[j].sl==cnt[i]){
				fre=a[sum[j].xb];
			}
		}
		if(i==n-1){
			ans=fre;
		}
		ans&=fre;
	}
	cout<<ans<<endl;
	return 0;
}
