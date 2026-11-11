#include<bits/stdc++.h>
using namespace std;
struct Stu{
	char w;
	long long m;
};
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	Stu a[n];
	long long ans=0;
	for(int i=0;i<n;i++){
		cin>>a[i].m>>a[i].w;
	}
	long long l=0,r=n-1;
	while(l<r){
		if(a[l].w==a[r].w){
			a[r].m-=a[l].m;
			a[l].m=0;
			if(a[r].m<0){
				a[l].m-=a[r].m;
				a[r].m=0;
			}
		}
		else{
			a[r].m-=a[l].m;
			ans+=a[l].m;
			a[l].m=0;
			if(a[r].m<0){
				ans+=a[r].m;
				a[l].m-=a[r].m;
				a[r].m=0;
			}
		}
		if(a[l].m==0){
			l++;
		}
		if(a[r].m==0){
			r--;
		}
	}
	cout<<ans<<'\n';
	return 0;
}
