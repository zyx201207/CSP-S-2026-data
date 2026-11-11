#include<bits/stdc++.h>
using namespace std;
long long n,sum=0;
struct m{
	long long a;
	string b;
};
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	m p[n];
	for(int i=0;i<n;i++){
		cin>>p[i].a>>p[i].b;
	}
	string lb=p[0].b,rb=p[n-1].b;
	int l=0,r=n-1,la=p[0].a,ra=p[n-1].a;
	while(l<r){
		if(lb!=rb){
			sum+=min(la,ra);
		}
		la-=min(la,ra);
		ra-=min(la,ra);
		if(la==0){
			l++;
			la=p[l].a;
			lb=p[l].b;
		}
		if(ra==0){
			r--;
			ra=p[r].a;
			rb=p[r].b;
		}
	}
	cout<<sum;
	return 0;
}
