#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N=2e5+10;
LL n;
struct Node{
	LL num;
	char c;
}a[N];	
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i].num>>a[i].c;
	LL sum=0,i=1,j=n;
	while(i<j){
		if(a[i].num>a[j].num){
			if(a[i].c!=a[j].c) sum+=a[j].num;
			a[i].num-=a[j].num;
			j--;
		}	
		else if(a[j].num>a[i].num){
			if(a[i].c!=a[j].c) sum+=a[i].num;
			a[j].num-=a[i].num;
			i++;
		}	
		else{
			if(a[i].c!=a[j].c) sum+=a[j].num;
			i++;
			j--;
		}	
	}	
	cout<<sum;
	return 0;
}
