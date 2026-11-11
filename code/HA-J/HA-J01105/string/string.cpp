#include<bits/stdc++.h>
using namespace std;
long long n,id_l,id_r,ans;
struct Node{
	long long num;
	char val;
}a[500005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].num>>a[i].val;
	}
	id_l=1;
	id_r=n;
	while(id_l<=id_r){
		if(a[id_l].num>a[id_r].num){
			if(a[id_l].val!=a[id_r].val){
				ans+=a[id_r].num;
			}
			a[id_l].num-=a[id_r].num;
			id_r--;
		}
		else if(a[id_l].num<a[id_r].num){
			if(a[id_l].val!=a[id_r].val){
				ans+=a[id_l].num;
			}
			a[id_r].num-=a[id_l].num;
			id_l++;
		}
		else{
			if(a[id_l].val!=a[id_r].val){
				ans+=a[id_l].num;
			}
			id_r--;id_l++;
		}
	}
	cout<<ans;
	return 0;
}
