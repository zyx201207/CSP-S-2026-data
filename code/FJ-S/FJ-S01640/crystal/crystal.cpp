#include<bits/stdc++.h>
using namespace std;
const long long N=6e5+10;
long long n,m;
struct Nodet{
	long long shu,Sum;
}a[N];
long long ans=-1;
bool cmp(Nodet x,Nodet y){
	return x.shu<y.shu;
}
int main(){
	//¸Älong long£¡£¡£¡£¡£¡£¡£¡£¡ 
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	long long i;
	cin>>n>>m;
	for(i=1;i<=n;i++){
		cin>>a[i].shu;
	}
	sort(a+1,a+1+n,cmp);
	for(i=1;i<=n;i++){
		a[i].Sum+=a[i-1].Sum+(a[i].shu-a[i-1].shu)*(i-1);
	}	
//	for(i=1;i<=n;i++){
//		cout<<a[i].shu<<" "<<a[i].Sum<<endl;
//	}
	long long S;
	for(i=n;i>=1;i--){
		long long l=1;
		long long r=i;
		while(l<=r){
			long long mid=(l+r)/2;
			S=a[i].Sum-(a[mid].Sum+(a[i].shu-a[mid].shu)*(mid-1));
			if(S<=m){
				r=mid-1;
				if(ans<i-mid+1) ans=i-mid+1;
			}
			else l=mid+1;
		}
	}
	cout<<ans;
//	long long cnt=0,Sum=0;
//	for(i=1;i<=n;i++){
//		if(a[i]==a[i-1]){
//			ans=ans+1;
//			goto wccc;
//		}
//		for(j=i;j>=1;j--){
//			if(cnt+(a[i]-a[j])>m){
//				//cout<<a[i]<<" "<<Sum<<endl;
//				cnt=0;
//				Sum=0;
//				break;
//			}
//			cnt+=a[i]-a[j];
//			Sum+=1;
//			ans=max(ans,Sum);
//		}
//		cnt=0;
//		Sum=0;
//		wccc:;
//	}
//	cout<<ans;
	return 0;
}

