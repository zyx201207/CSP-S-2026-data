#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n;
long long sum;
struct node{
	long long x;
	char a;
}q[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>q[i].x>>q[i].a;
	}
	int l=1,r=n;
	while(l<r){
		if(q[l].a!=q[r].a){
			if(q[l].x==q[r].x) {
				sum+=q[l].x;
				q[l].x=q[r].x=0;
				l++,r--;
			} else if(q[l].x<q[r].x){
				sum+=q[l].x;
				q[r].x-=q[l].x;
				q[l].x=0;
				l++;
			}else{
				sum+=q[r].x;
				q[l].x-=q[r].x;
				q[r].x=0;
				r--;
			}
		}else {
			if(q[l].x==q[r].x) q[l].x=q[r].x=0,l++,r--;
			else if(q[l].x>q[r].x) q[l].x-=q[r].x,q[r].x=0,r--;
			else if(q[l].x<q[r].x) q[r].x-=q[l].x,q[l].x=0,l++;
		}
	}
	cout<<sum;
	return 0;
}
