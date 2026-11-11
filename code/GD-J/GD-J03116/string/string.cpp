#include<bits/stdc++.h>
using namespace std;
const int N=2*1e5+10;
struct oi{
	int sum;
	char s;
}a[N];
long long n,l,r,sum,b,len=1,o;
char p;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	cin>>o>>p;
	a[0].sum=o,a[0].s=p;
	for(int i=2;i<=n;i++){
		cin>>o>>p;
		if(p==a[len-1].s) a[len-1].sum+=o;
		else{
			a[len].s=p,a[len].sum=o;
			len++;
		}
	}
	l=0,r=len-1;
	while(l<r){
		b=min(a[l].sum,a[r].sum);
		if(a[l].s!=a[r].s) sum+=b;
		if(a[l].sum==a[r].sum){
			l++,r--;
		}else if(a[l].sum>a[r].sum){
			a[l].sum-=b;
			r--;
		}else{
			a[r].sum-=b;
			l++;
		}
	}
	cout<<sum;
	return 0;
} 
