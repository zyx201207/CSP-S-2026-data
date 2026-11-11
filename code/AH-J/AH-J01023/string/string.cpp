#include<bits/stdc++.h>
using namespace std;
int n;
long long sum;
struct node{
	int x;
	char c;
}a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].c;
	}
	int l=1,r=n;
	while(l<=r){
		if(a[l].c==a[r].c){
			if(a[l].x>a[r].x){
				a[l].x-=a[r].x;
				r--;
			}else{
				a[r].x-=a[l].x;
				l++;
			}
		}else{
			if(a[l].x>a[r].x){
				sum+=a[r].x;
				a[l].x-=a[r].x;
				r--;
			}else{
				sum+=a[l].x;
				a[r].x-=a[l].x;
				l++;
			}
		}
	}
	cout<<sum;
	return 0;
}
