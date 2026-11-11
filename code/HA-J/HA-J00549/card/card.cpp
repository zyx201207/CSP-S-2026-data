#include<bits/stdc++.h>
using namespace std;
struct va{
	long long z,l,r;
}a[500005];
map<long long,long long> m;
long long s[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,mm;
	cin>>n>>mm;
	for(int i=1;i<=n;i++){
		cin>>a[i].z;
		if(m.count(a[i].z)){
			a[i].l=m[a[i].z];
			a[m[a[i].z]].r=i;
		}
		m[a[i].z]=i;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			while(a[j].r!=0){
				j=a[j].r;
			}
			s[a[j].z]++;
		}
	}
	for(int i=1;i<=mm;i++){
		cout<<s[i]<<" ";
	}
	return 0;
}
