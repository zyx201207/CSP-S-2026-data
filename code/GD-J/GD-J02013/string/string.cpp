#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long k;
struct st{
	long long num;
	char c;
}a[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%d %c",&a[i].num,&a[i].c);
		k+=a[i].num;
	}
	long long ans=0;
	int idx=1,idy=n;
	while(1){
		if(idx>=idy){
			break;
		}
		if(a[idx].c!=a[idy].c) ans+=min(a[idx].num,a[idy].num);
		if(a[idx].num>a[idy].num){
			a[idx].num-=a[idy].num;
			idy--;
		}else if(a[idx].num<a[idy].num){
			a[idy].num-=a[idx].num;
			idx++;
		}else{
			idx++;
			idy--;
		}
	}
	cout<<ans;
	return 0;
}
