#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	struct node{
		int num;
		char s;
	}a[200005];
	long long tol=0;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].num>>a[i].s;
		tol+=a[i].num; 
	}
	long long ans=tol/2;;
	int right=tol,left=0,rpos=1,lpos=n;
	while(left<right){
		if(a[lpos].s==a[rpos].s){
			ans-=min(a[lpos].num,a[rpos].num);
		}
		left+=min(a[lpos].num,a[rpos].num);
		right-=min(a[lpos].num,a[rpos].num);
		if(a[lpos].num>a[rpos].num){
			rpos--;
			a[lpos].num-=a[rpos].num;
		}
		else{
			lpos--;
			a[rpos].num-=a[lpos].num;
		}
	}
	cout<<ans;
	return 0;
}
