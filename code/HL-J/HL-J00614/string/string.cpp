#include <bits/stdc++.h>
using namespace std;
struct node{
	int l;
	char x;
	long long w;
}a[200005];
int n,p=0,k;
long long sum=0;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].l>>a[i].x;
		a[i].w=a[i-1].w+a[i].l;
	}
	long long len=a[n].w;
	if(len%2==1){
		p=1;
	}
	if(p==1){
		long long mid=len-len/2;
		int now=0;
		for(int i=1;i<=n;i++){
			if(mid>a[i-1].w && mid<=a[i].w){
				now=i;
				break;
			}
		}
		for(int i=n;i>=now+1;i--){
			swap(a[i+1],a[i]);
		}
		n+=1;
		a[now+1].l=a[now].w-mid;
		a[now+1].x=a[now].x;
		a[now].l=a[now].l-a[now+1].l-1;
		k=now;
	}
	else{
		long long mid=len/2;
		int now=0;
		for(int i=1;i<=n;i++){
			if(mid>a[i-1].w && mid<=a[i].w){
				now=i;
				break;
			}
		}
		for(int i=n;i>=now+1;i--){
			swap(a[i+1],a[i]);
		}
		n+=1;
		a[now+1].l=a[now].w-mid;
		a[now+1].x=a[now].x;
		a[now].l=a[now].l-a[now+1].l;
		k=now;
	}
	int l=1;
	int r=n;
	while(l<=k && r>k){
		if(a[l].x==a[r].x){
			if(a[l].l>a[r].l){
				a[l].l-=a[r].l;
				a[r].l=0;
				r--;
			}else if(a[l].l<a[r].l){
				a[r].l-=a[l].l;
				a[l].l=0;
				l++;
			}else{
				a[l].l=0;
				a[r].l=0;
				l++;
				r--;
			}
		}else{
			if(a[l].l>a[r].l){
				sum+=a[r].l;
				a[l].l-=a[r].l;
				a[r].l=0;
				r--;
			}
			else if(a[l].l<a[r].l){
				sum+=a[l].l;
				a[r].l-=a[l].l;
				a[l].l=0;
				l++;
			}else{
				sum+=a[l].l;
				a[l].l=0;
				a[r].l=0;
				l++;
				r--;
			}
		}
	}
	if(a[k].l!=0){
		sum+=a[k].l;
	}
	if(a[k+1].l!=0){
		sum+=a[k+1].l;
	}
	cout<<sum;
	return 0;
} 
