#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n;
struct node{
	long long a;
	char c;
}q[N],x[N];
long long sum;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	int cnt=0;
	for(int i=1;i<=n;i++){
		cin>>q[i].a>>q[i].c;
		if(q[i].c==q[i-1].c){
			x[cnt].a=q[i].a+q[i-1].a;
			x[cnt].c=q[i].c;
			q[i].a+=q[i-1].a;
		}else{
			cnt++;
			x[cnt].a=q[i].a;
			x[cnt].c=q[i].c;
		}
	}
	int l=1,r=cnt;
	while(l<r){
		if(x[l].c==x[r].c){
			if(x[l].a<x[r].a){
				x[r].a-=x[l].a;
				l++;
			}else if(x[l].a>x[r].a){
				x[l].a-=x[r].a;
				r--;
			}else{
				l++;
				r--;
			}
		}else{
			if(x[l].a<x[r].a){
				sum+=x[l].a;
				x[r].a-=x[l].a;
				l++;
			}else if(x[l].a>x[r].a){
				sum+=x[r].a;
				x[l].a-=x[r].a;
				r--;
			}else{
				sum+=x[l].a;
				l++;
				r--;
			}
		}
	}
	cout<<sum;
	return 0;
} 
