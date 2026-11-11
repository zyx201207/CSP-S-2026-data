#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll a[2000005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ll n,m;cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}sort(a,a+n);
	/*for(int i=0;i<n;i++){
		cout<<a[i]<<endl;;
	}*/
	ll m1=m;
	int i;
	//cout<<m1<<endl;
	for(i=1;i<n and m1>-1;i++){
		//cout<<a[i]<<' '<<i<<endl;
		m1-=(a[i]-a[i-1])*i;
		//cout<<m1<<endl;
	}i--;
	//cout<<m1<<endl;
	/*int backup_i=i;bool fl=0;
	m1+=(a[i]-a[i-1])*i;
	if(m1>0){
		for(int j=a[i-1];j<a[i];j++){
			if(m1-i>0){
				i++;
			}else if(m1-i==0){
				break;
			}else fl=1;
		}
	}if(fl) i=backup_i;*/
	cout/*<<a[i]<<endl*/<<i;
	return 0;
}
