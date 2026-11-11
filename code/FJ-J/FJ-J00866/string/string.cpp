//#include<bits/stdc++.h>
//using namespace std;
//
//int main(){
//	freopen("string.in","r",stdin);
//	freopen("string.out","w",stdout);
//	char a[200005];
//	char b[100005];
//	long long y[100005];
//    long long x[100005];
//    unsigned long long ans=0;
//	int n;
//	cin>>n;
//	unsigned long long sum=0;
//	for(int i=1;i<=n;i++){
//		cin>>x[i]>>a[i];
//		sum+=x[i];
//	}
//	sum/=2;
//	sum+=1;
//	int l=1,r=n;
//	while(l<=r){
//		b[l]=a[r];
//		y[l]=x[r];
//		l++,r--;
//	}
//	int ll=1,gg=1;
//	while(ll<n/2&&gg<n/2){
//		if(a[ll]!=b[gg]){
//			if(x[ll]>y[gg]){
//				ans+=y[gg];x[ll]-=y[gg];
//				gg++;
//			}else{
//				ans+=x[ll];y[gg]-=x[ll];
//				ll++;
//			}
//		}else{
//			if(x[ll]>y[gg]){
//				x[ll]-=y[gg];
//				gg++;
//			}else{
//				y[gg]-=x[ll];
//				ll++;
//			}
//		}
//	}
//	cout<<ans;
//	return 0;
//}
#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	string c;
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		string a;
		cin>>x>>a;
		for(int j=1;j<=x;j++){
			c+=a;
		}
	}
	string s;
	s=c;
	long long l=0,r=s.size()-1;
	while(l<=r){
		swap(s[l],s[r]);
		l++;
		r--;
	}
	long long ans=0;
	for(int i=0;i<=n/2+1;i++){
		if(c[i]!=s[i]){
			ans++;
		}
	}
	cout<<ans;
}
