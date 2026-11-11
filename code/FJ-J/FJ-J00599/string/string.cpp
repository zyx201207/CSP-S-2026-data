#include<iostream>
#include<string>
#include<cmath>
using namespace std;
struct stu{
	long long num;char c;
}a[200005];
long long n,cnt,l,r;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].num>>a[i].c;
	}
	l=1,r=n;
	long long lsbl=0;//¡Ÿ ±±‰¡ø 
	while(l<r){
		//cout<<l<<" "<<r<<endl;
		if(a[l].c!=a[r].c){
			lsbl=min(a[r].num,a[l].num);
			a[l].num-=lsbl;a[r].num-=lsbl;
			cnt+=lsbl;
		}else{
			lsbl=min(a[r].num,a[l].num);
			a[l].num-=lsbl;a[r].num-=lsbl;
		}
		if(a[l].num==0){
			l++;
		}
		if(a[r].num==0){
			r--;
		}
	}
	cout<<cnt;
	return 0;
} 
