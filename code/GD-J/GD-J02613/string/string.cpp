#include<bits/stdc++.h>
using namespace std;
struct node{
	int d;
	char v;
}a[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].d>>a[i].v;
	}
	int l=1,r=n;
	long long sum=0;
	while(l<r){
		int t=abs(a[l].d-a[r].d);
		if(a[l].d>a[r].d){
			if(a[r].v!=a[l].v) sum+=a[r].d;
			int tt;
			while(1){
				r--;
				if(a[r].d>=t){
					a[r].d-=t;
					if(a[r].v!=a[l].v) sum+=t;
					break;
				}
				if(a[r].v!=a[l].v) sum+=a[r].d;
				t-=a[r].d;
			}
			l++;
		}
		else{
			a[l+1].d-=t;
			if(a[r].v!=a[l].v) sum+=a[l].d;
			
			int tt;
			while(1){
				l++;
				if(a[l].d>=t){
					a[l].d-=t;
					if(a[l].v!=a[r].v) sum+=t;
					break;
				}
				if(a[l].v!=a[r].v) sum+=a[l].d; 
				t-=a[l].d;
			}
			r--;
		}
	}
	cout<<sum;
	return 0;
}

