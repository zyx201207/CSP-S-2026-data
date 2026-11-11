#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long a[N];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	long long cnt=0,res=0;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
//	for(int i=0;i<n;i++){
//		cout<<a[i];
//	}
	for(int i=0;i<n;i++){
		if(cnt+res*(a[i]-a[i-1])<=m){
//			cout<<a[i]<<"  "<<a[i-1]<<endl;
//			cout<<"qian"<<cnt<<" "<<res<<endl;
			cnt+=res*(a[i]-a[i-1]);
			res++;
//			cout<<"hou"<<cnt<<" "<<res<<endl;
//			cout<<i<<endl<<endl;
		}
		else{
			break;
		}
	}
	printf("%d",res);
	return 0;
}
