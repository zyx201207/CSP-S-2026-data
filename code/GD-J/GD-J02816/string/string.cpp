#include<bits/stdc++.h>
using namespace std;
const int N=2*1e5+101;
long long n,ans;
struct node{
	char s;
	long long x,id;
}q[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>q[i].x>>q[i].s;
		q[i].id=q[i].s-'a'+1;
	}
	long long l=1,r=n;
	while(l<r){
		if(l==r)break;
		if(q[l].id==q[r].id){
			if(q[l].x==q[r].x){
				l++;r--;
			}else if(q[l].x>q[r].x){
				q[l].x-=q[r].x;
				r--;
			}else{
				q[r].x-=q[l].x;
				l++;
			}
		}else{
			if(q[l].x==q[r].x){
				ans+=q[l].x;
				l++;r--;
			}else if(q[l].x>q[r].x){
				ans+=q[r].x;
				q[l].x-=q[r].x;
				r--;
			}else{
				ans+=q[l].x;
				q[r].x-=q[l].x;
				l++;
			}
		}
	}
	cout<<ans;
	return 0;
} 
