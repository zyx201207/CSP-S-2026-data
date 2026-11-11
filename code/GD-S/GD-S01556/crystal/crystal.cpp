#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],minn=6666666666666,maxx,ma,asd;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<=minn) minn=a[i];
		if(a[i]>=maxx) maxx=a[i];
	}
	long long s,qwe;
	for(int i=minn;i<=maxx;i++){
		s=0;
		qwe=0;
		for(int j=1;j<=n;j++){
			if(a[j]<i){
				if(s+(i-a[j])>m){
					break;
				}
				else {
					s+=i-a[j];
					asd++;
				}
			}
			if(a[j]==i){
				qwe++;
			}
		}
		asd+=qwe;
		if(asd>=ma) ma=asd;
		asd=0;
	}
	cout<<ma;
	return 0;
}
