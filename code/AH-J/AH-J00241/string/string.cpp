#include<bits/stdc++.h>
using namespace std;
struct stu{
	long long gs;
	char zm;
};
stu a[110000];
long long n,l,r,s=0,xs=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	l=1,r=n;
	for(long long i=1;i<=n;i++){
		cin>>a[i].gs>>a[i].zm;
		s+=a[i].gs;
	}
	while(s!=0){
		if(l==r){
			break;
		}
		if(a[l].gs>a[r].gs){
			if(a[l].zm==a[r].zm){
				a[l].gs=a[l].gs-a[r].gs;
				r--;
			}else{
				xs+=a[r].gs;
				a[l].gs=a[l].gs-a[r].gs;
				r--;
			}
		}else{
			if(a[l].zm==a[r].zm){
				a[r].gs=a[r].gs-a[l].gs;
				l++;
			}else{
				xs+=a[l].gs;
				a[r].gs=a[r].gs-a[l].gs;
				l++;
			}
		}
	}
	cout<<xs;
	return 0;
}
