#include<bits/stdc++.h>
using namespace std;
int n,s1,s2;
long long m1,m2,a[1000000];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m1;
	for(int i=0;i<n;i++){
		scanf("%lld",&a[i]);
	}
	a[n]=-1;
	sort(a,a+n);
	for(int i=0;i<n;i++){
		if(a[i]==a[i+1]){
			continue;
		}
		m2=m1;
		for(int j=i;j>=0&&m2>=a[i]-a[j];j--){
			m2-=a[i]-a[j];
			s2++;
		}
		s1=max(s1,s2);
		s2=0;
	}
	cout<<s1;
	return 0;
}
