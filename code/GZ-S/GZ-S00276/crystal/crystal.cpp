//GZ-S00276贵阳中天中学 蒲科印
#include<bits/stdc++.h>
using namespace std;

const int N = 5e5+10;
long long n,m;
long long maxx=0;
long long minn=INT_MIN;
long long c[N],a[N];
long long s[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(a[1]<0){
		int cc = abs(a[1]);
		for(int i=1;i<=n;i++){
			a[i]+=cc;
		}
	}
	s[1]=a[1];
	int sumn=0;
	for(int i=1;i<n;i++){
		c[i]=a[i+1]-a[i];
		s[i]+=c[i]+s[i-1];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			sumn+=s[j];
		}
		if(m<=sumn){
			maxx++;
			break;
		}
		else maxx=i+1;
	}
	if(maxx>n){
		cout<<n;
		return 0;
	}
	cout<<maxx;
	return 0;
}

