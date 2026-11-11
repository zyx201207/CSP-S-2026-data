#include <bits/stdc++.h>
using namespace std;
struct num{
	long long k;
	bool f[100];
}a[200005];
bool cmp(num a,num b){return a.k>b.k;}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	bool ta=1;
	int n,m;
	int max=-1;
	long long min=1e10;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].k;
		if(a[i].k>max)max=a[i].k;
		if(a[i].k<min)min=a[i].k;
		bool b[100];
		int z=a[i].k,day=1;
		while(z){
			if(z%2==1)b[day]=1;
			else b[day]=0;
			z/=2;
			day++;
		}
		int w=1;
		for(int j=day-1;j>=1;j--){
			if(b[j]==0)ta=0;
			a[i].f[w]=b[j];
			w++;
		}
	}
	if(m==1){
		cout<<max<<endl;
		return 0;
	}
	if(m==n){
		cout<<min<<endl;
		return 0;
	}
	if(ta==1){
		sort(a+1,a+n+1,cmp);
		cout<<a[m].k<<endl;
		return 0;
	}
	sort(a+1,a+n+1,cmp);
	cout<<a[m].k<<endl;
	return 0;
}
