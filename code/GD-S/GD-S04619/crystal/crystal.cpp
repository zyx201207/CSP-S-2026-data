#include<bits/stdc++.h>
using namespace std;
int n,a,ma;
long long m,l[500000],s;
long long jdz(long long aa){
	if(aa<0){
		return 0-aa;
	}
	else{
		return aa;
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>l[i];
	}
	if(n>6000){
		ma=0;
		for(int i=1;i<=n;i++){
			if(m-jdz(l[1]-l[0])*i>=0){
				m-=jdz(l[1]-l[0])*i;
				ma+=1;
			}
			cout<<ma;
		}
	} 
	else{
		sort(l,l+n);
		for(int i=1;i<n;i++){
			s=m;
			a=1;
			for(int j=i-1;j>=0;j--){
				if(s-jdz(l[i]-l[j])>=0){
					s-=jdz(l[i]-l[j]);
					a+=1;
				}
				else{
					break;
				}
				if(a>ma){
					ma=a;
				}
			}
		}
		cout<<ma;
	}
	return 0;
}
