#include<bits/stdc++.h>
using namespace std;
long long n;
struct aaa{
	int q;
	char k;
}a[200008];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i].q>>a[i].k;
	}
	long long r=0,l=n-1,s=0;
	while(r<=l){
		if(a[r].k==a[l].k){
			a[r].q-=min(a[r].q,a[l].q);
			a[l].q-=min(a[r].q,a[l].q);
			if(!a[r].q) r++;
			if(!a[l].q) l--;
		}
		else if(a[r].q>=a[l].q){
			s+=a[l].q;
			a[r].q-=a[l].q;
			if(!a[r].q) r++;
			l--;
		}
		else{
			s+=a[r].q;
			a[l].q-=a[r].q;
			if(!a[l].q) l--;
			r++;
		}
	}
	cout<<s;
}
