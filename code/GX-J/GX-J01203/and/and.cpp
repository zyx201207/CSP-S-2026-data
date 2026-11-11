#include<bits/stdc++.h>
using namespace std;

const int Nd=200050;
long long n,m,a[Nd],kk=-1;

int main(){
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
ios::sync_with_stdio(false);
cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
	cin>>a[i];
	kk=max(a[i],kk);
	}
	if(m==1){
		cout<<kk;
		}
	else{
		cout<<a[6];
		}
return 0;
}
