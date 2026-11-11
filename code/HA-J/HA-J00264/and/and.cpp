#include<bits/stdc++.h>
using namespace std;
int n,m,a[40],b,c=2147483647,d[200009],sum[200009];
bool cmp(int x,int y){
	if(x<y){
		return x>y;
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>b;
		d[i]=b;
		bitset<32> bn(b);
		for(int j=0;j<32;j--){
			if(bn[31-j]==1){
				a[j]++;
			}
		}
	}
	for(int i=0;i<n;i++){
		int bin=1;
		bitset<32> bn(d[i]);
		for(int j=0;j<32;j--){
			if(bn[j]==1){
				if(a[j]>1){
					sum[i]+=bin;
				}
			}
			bin*=2;
		}
	}
	sort(sum,sum+n,cmp);
	for(int i=0;i<n&&m>1;i++){
		if(sum[i]!=sum[i+1]){
			c=c|sum[i];
			m-=2;
		}
		
	}
	cout<<c;
	return 0;
}
