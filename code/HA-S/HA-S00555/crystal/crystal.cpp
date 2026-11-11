#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[1000005],ans,A;
//int qj[1000005];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)
		scanf("%lld",&a[i]);
	sort(a,a+n);
	int tmp=0;
	int cha=0;
	for(int i=0;i<n;i++){
		tmp=m;
		ans=1;
		cha=0;
		for(int j=i;j>=0;j--){
			cha=a[i]-a[j];
			if(tmp-cha<0)break;
			tmp-=cha;
			ans++;
		}
		A=max(A,ans);
	}
	
	
	
	cout<<A-1;
	return 0;
}

//	//erfen
//	for(int i=1;i<=n;i++)
//		qj[i]=qj[i-1]+a[i];
//	int tmp=0;
//	for(int i=1;i<=n;i++){
//		tmp=m;
//		ans=1;
//		int l=1,r=i+1;
//		int mid=(l+r-1)/2;
//		
//		while(r>l){
//			cout<<"L"<<l<<" r"<<r<<" mid"<<mid<<endl;
//			mid=(l+r-1)/2;
//			cout<<[i]*(i-mid)<<"  "<<qj[i]-qj[mid-1]<<endl;
//			if(a[i]*(i-mid)-(qj[i]-qj[mid-1])>m){
//				l=mid;
//			}else{
//				r=mid-1;
//			}
//		}
//		ans=mid;
////		cout<<ans;
//		A=max(ans,A);
//	}
	//ERFEN

