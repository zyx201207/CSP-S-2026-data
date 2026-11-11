#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],t,t2,ma=-1;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>t;
		if(t>ma) ma=t;
		t2=0;
		while(t>1){
			t2=t2*10+t%2;
			t/=2;
		}
		a[i]=t2;
	} 
	if(m==1){
		cout<<ma;
		return 0;
	}
	return 0;
}
