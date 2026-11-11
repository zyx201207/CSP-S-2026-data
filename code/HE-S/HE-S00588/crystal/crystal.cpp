#include<bits/stdc++.h>
using namespace std;
int n,c=0,mm=0,nu=1;
long long m,m2;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	m2=m;
	long a[n+1];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	if (n==1){
		c=1;
	}
	else if (m==0){
		int chang=1;
		for (int i=0;i<n;i++){
			if (a[i]==a[i+1])chang+=1;
			else chang=1;
			if (chang>mm)mm=chang;
		}
		c=mm;
	}
	else {
		for (int i=0;i<n;i++){
			nu=1;
			m=m2;
			int l=i-1;
			int r=i+1;
			for (int j=r;j<n;j++){
				if (a[i]==a[j])	{
					nu++;
				}
				else  {
					j=n;
				}
			}
			for (int p=l;p>=0;p--){
				if (a[i]==a[p])	nu++;
				else {
					if (m>=(a[i]-a[p])){
						m-=(a[i]-a[p]);
						nu++;	
					}
					else {
						p=-1;
					}
				}
			}
			if(nu>c)c=nu;
		}
	}
	cout<<c<<'\n';
	return 0;
}
