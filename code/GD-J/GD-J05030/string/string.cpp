#include<bits/stdc++.h>
using namespace std;
long long n;
long sum,ans;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	s=" ";
	for(int i=1;i<=n;i++){
		long long x;
		char c;
		cin>>x>>c;
		for(long long j=sum+1;j<=sum+x;j++){
			s+=c;
		}
		sum+=x;
	}
	long long i,j;
	if(sum%2==0)i=sum/2,j=sum/2+1;
	else i=j=sum/2+1;
	for(;i>=1;i--,j++){
		if(s[i]!=s[j])ans++;
	}
	cout<<ans;
	return 0;
}
//#include<bits/stdc++.h>
//using namespace std;
//long long n,ans,cl,cr;
//struct stu{
//	long long x,y;
//	char c;
//}a[200001];
//int main(){
////	freopen("string.in","r",stdin);
////	freopen("string.out","w",stdout);
//	cin>>n;
//	long long sum=0;
//	for(long long i=1;i<=n;i++){
//		long long x;
//		cin>>x>>a[i].c;
//		a[i].x=sum+1,a[i].y=sum+x;
//		sum+=x;
//	}
//	long long l,r,l2,r2;
//	if(sum%2==1){
//		cl=sum/2+1;
//		cr=sum/2+1;
//		long long k=-1;
//		for(long long i=1;i<=n;i++){
//			if(a[i].x<=(sum/2+1)&&a[i].y>=(sum/2+1)){
//				k=i;
//			}
//		}
//		l=a[k].x,r=a[k].y;
//		l2=k;
//		r2=k;
//	}
//	else{
//		cl=sum/2;
//		cr=sum/2+1;
//		long long k=-1,k2=-1;
//		for(long long i=1;i<=n;i++){
//			if(a[i].x<=(sum/2)&&a[i].y>=(sum/2)){
//				k=i;
//			}
//			if(a[i].x<=(sum/2+1)&&a[i].y>=(sum/2+1)){
//				k2=i;
//			}
//		}
//		l=a[k].x,r=a[k2].y;
//		l2=k;
//		r2=k2;
//	}
//	//cout<<l2<<" "<<r2;
//	while(l!=1&&r!=sum){
//		cout<<l<<" "<<l2<<" "<<r<<" "<<r2<<endl;
//		if(a[l2].c!=a[r2].c){
//			ans+=abs(l-(sum-r));
//		}
//		if(cl-l<r-cr){
//			l=cl-(a[r2].y-cr)max;
//			l2--;
//		}
//		if(cl-l>r-cr){
//			r=cr+(cl-a[l2].x);
//			r2++;
//		}
//		if(l==r){
//			l=cl-(a[r2].y-cr);
//			r=cr+(cl-a[l2].x);
//			l2--,r2++;
//		}
//	}
//	cout<<ans;
//	return 0;
//}


