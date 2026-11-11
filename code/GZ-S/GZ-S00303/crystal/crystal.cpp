//何乾睿 GZ-S00303 贵阳市南明区华麟学校 
#include <bits/stdc++.h>
using namespace std;
int n,s;
long long a[5000010],m,b[5000010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	long long s=0;
	for(int i=1;i<=n;i++){
		s+=a[i];
	}
	s/=n;
	long long j=0;
	for(int i=1;i<=n;i++){
		if(a[i]>=j && a[i]<=s){
			j=a[i];
		} 
	}
	int f=0;
	while(m>0){
		int t=0,e=0;
		for(int i=1;i<=n;i++){
			if(a[i]>=t && a[i]<=j && b[i]==0){
				t=a[i];
				e=i;
			} 
		}
		b[e]=1;
		m-=(j-t);
		a[e]=j;
	}
	for(int i=1;i<=n;i++){
		if(a[i]==j) f++;		
	}
	cout<<f;
	return 0;
}
