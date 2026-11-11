#include<bits/stdc++.h>
using namespace std;
const int N=500010;
typedef long long ll;
ll a[N];
int ans=1;
int ird(){
	int o=0;
	char a;
	a=getchar();
	while(a>='0'&&a<='9'){
		o=o*10+(a-'0');
		a=getchar();
	}
	return o;
}
ll rd(){
	ll o=0;
	int x=1;
	char a;
	a=getchar();
	while((a<'0'||a>'9')&&a!='-'){
		a=getchar();
	}
	if(a=='-'){
		x=-1;
		a=getchar();
	}
	while(a>='0'&&a<='9'){
		o=o*10+(a-'0');
		a=getchar();
	}
	return o*x;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	ll m;
	n=ird();
	m=rd();
//	cout<<n<<' '<<m<<"\n";
	for(int i=0;i<n;i++){
		a[i]=rd();
//		cout<<a[i]<<' ';
	}
//	cout<<"\n";
	
	sort(a,a+n);
	int l=0,r=1;
	while(r<n){
		ll x=(a[r]-a[r-1])*(r-l);
		if(ans<r-l) ans=r-l;
		if(x>m){
			m+=a[r-1]-a[l];
			l++;
		}
		else{
			m-=x;
			r++;
		}
	}
	printf("%d",ans);
	return 0;
}
