#include<bits/stdc++.h>
using namespace std;
struct jjc{
	long long s;
	char z;
}a[200001];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	long long ma=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%d %c",&a[i].s,&a[i].z);
	}
	int l=1,r=n;
	while(r>l){
		if(a[r].s>a[l].s){
			a[r].s-=a[l].s;
			if(a[r].z!=a[l].z) ma+=a[l].s;
			l++;
		}else if(a[r].s<a[l].s){
			a[l].s-=a[r].s;
			if(a[r].z!=a[l].z) ma+=a[r].s;
			r--;
		}else {
			if(a[r].z!=a[l].z) ma+=a[r].s;
			r--;
			l++;
		}
	}
	cout<<ma;
	return 0;
} 
