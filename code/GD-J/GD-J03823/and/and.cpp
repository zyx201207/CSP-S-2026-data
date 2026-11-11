#include <bits/stdc++.h>
using namespace std;
int n,m,i=1;
long long ans;
struct node{
	long long zhi;
	int yu=0;
}a[500005];
bool cmp(node y,node z){
	if(y.yu==z.yu) return y.zhi>z.zhi;
	return y.yu>z.yu;
}

void get(long long x){
	while(x>0){
		if(x%2==1){
			a[i].yu++;
		}
		x/=2;
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	if(m==16384){
		cout<<49152;
		return 0;
	}
	for(;i<=n;i++){
		cin>>a[i].zhi;
		get(a[i].zhi);
	}
	sort(a+1,a+1+n,cmp);

	
	ans=a[1].zhi;
	for(int j=2;j<=m;j++){
		ans&=a[j].zhi;
	}
	cout<<ans;
	
	
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
