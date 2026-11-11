#include<bits/stdc++.h>
using namespace std;
int n;
long long sum;
struct nd{
	int x;
	char c;
}a[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%d %c",&a[i].x,&a[i].c);
	}
	int l=1,r=n;
	while(l<r){
		if(a[l].c==a[r].c){
			int k=min(a[l].x,a[r].x);
			a[l].x-=k;a[r].x-=k;
			if(a[l].x==0) l++;
			if(a[r].x==0) r--;
		}
		else{
			int k=min(a[l].x,a[r].x);
			sum+=k;
			a[l].x-=k;a[r].x-=k;
			if(a[l].x==0) l++;
			if(a[r].x==0) r--;
		}
	}
	cout<<sum;
	return 0;
}

