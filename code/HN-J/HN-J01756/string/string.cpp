#include<bits/stdc++.h>
using namespace std;
struct node{
	long long num;
	char c;
}a[200005];
int n,sum,q=0;
long long ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int k=0;
	a[0].num=0;
	for(int i=1;i<=n;i++){
		int x;
		char y;
		cin>>x>>y;
		if(a[k].c!=y){
			k++;
			a[k].num=x;
			a[k].c=y;
		}
		else
			a[k].num+=x;
	}
	sum=k;
	int j=1;
	while(j<=sum/2){
		if(a[j].num==a[sum-j+1+q].num){
			j++;
			continue;
		}
		int t=min(a[j].num,a[sum-j+1+q].num);
		if(t==a[sum-j+1+q].num){
			a[j].num-=t;
			q--;
		}
		else{
			a[sum-j+1+q].num-=t;
			sum++;
			q++;
			j++;
		}
		ans+=t;
	}
	cout<<ans;
	return 0;
} 
