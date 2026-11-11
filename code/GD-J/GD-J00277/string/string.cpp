#include<bits/stdc++.h>
using namespace std;
int t,i=1,j;
long long ans;
struct node{
	long long x;
	string s;
}a[200001]; 
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&t);
	for(int i=1;i<=t;i++){
		scanf("%lld",&a[i].x);
		cin>>a[i].s;
	}j=t;
	while(i<j){
		if(a[j].x<a[i].x){
			if(a[i].s==a[j].s)a[i].x-=a[j].x;
			else{
				ans+=min(a[i].x,a[j].x);
				a[i].x-=a[j].x;
			}j--;
		}else if(a[j].x>a[i].x){
			if(a[i].s==a[j].s)a[j].x-=a[i].x;
			else{
				ans+=min(a[i].x,a[j].x);
				a[j].x-=a[i].x;
			}i++;
		}else{
			if(a[i].s!=a[j].s)ans+=a[i].x;
			i++,j--;
		}
	}printf("%lld",ans);
	return 0;
}
