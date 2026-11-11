#include <bits/stdc++.h>
using namespace std;
int z=-1;
struct yzy{
	int x,s;
	int a[50];
}b[200005];
int n,m;
bool cmp(yzy x,yzy y){
	return x.s>y.s; 
}
int main(){
	freopen("and.in","r",stdin);
	freopen ("and.out","w",stdout);	
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>b[i].x;
		int t=b[i].x;
		int j=0;
		while (t>0){
			b[i].a[j]=t%2;
			b[i].s+=t%2; 
			t/=2;
			j++;
		} 
	}
	sort(b+1,b+1+n,cmp);
	for (int i=2;i<=m;i++){
		for (int j=0;j<=50;j++){
			if (b[1].a[i]==b[i].a[j]){
				
			}else{
				b[1].a[i]=0;
			}
		}
	}
	long long r=0;
	for (int i=0;i<=50;i++){
		if (b[1].a[i]==1){
			r+=pow(2,i);
		}
	} 
	cout<<r;
	return 0;
} 
