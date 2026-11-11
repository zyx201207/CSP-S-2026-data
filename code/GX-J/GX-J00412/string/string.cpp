#include<bits/stdc++.h>
using namespace std;
long long n,sum,cnt,l,r;
struct node{
	long long x;
	char y;
};
node a[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].y;
	}
	l=1,r=n;
	while(l<=r){
		if(a[l].y!=a[r].y){
			if(a[l].x>a[r].x){
				sum+=a[r].x;
				a[l].x-=a[r].x;
				r--;
			}
			else if(a[l].x==a[r].x){
				sum+=a[l].x;
				l++,r--;
			}
			else{
				sum+=a[l].x;
				a[r].x-=a[l].x;			
				l++;
			}
		}
		else{
			if(a[l].x>a[r].x){
				a[l].x-=a[r].x;
				r--;
			}
			else if(a[l].x==a[r].x){
				l++,r--;
			}
			else{
				a[r].x-=a[l].x;			
				l++;
			}
		}
	}
	cout<<sum;
return 0;
}
