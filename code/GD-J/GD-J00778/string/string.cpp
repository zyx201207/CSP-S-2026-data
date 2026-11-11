#include<bits/stdc++.h>
using namespace std;
int n;
struct fu{
	double l,r;
	char c;
}a[200005];
double t=1;
long long ans=0;
bool g=false;
int mi;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		double u;
		cin>>u;
		a[i].l=t;
		a[i].r=t+u-1;
		cin>>a[i].c;
		t+=u;
	}
	t--;
	t=(t+1.0)/2.0;
	int mi=t;
	int l,r;
	if(mi!=t){
		g=true;
		for(int i=1;i<=n;i++){
			if(a[i].l<=t&&a[i].r>=t){
				l=i;  r=i;
				break;
			}
			if(a[i].r+0.5==t){
				l=i; r=i+1;
				break;
			}
		}	
	}else{
		for(int i=1;i<=n;i++){
			if(a[i].l<=t&&a[i].r>=t){
				l=i;  r=i;
				break;
			}
		}	
	}
	
	while(l>=1&&r<=n){
		long long j=min(t-a[l].l,a[r].r-t)-max(t-a[l].r,a[r].l-t)+1;
		if(a[l].c!=a[r].c)ans+=j;
		if(t-a[l].l>a[r].r-t){
			r++;
		}else if(t-a[l].l<a[r].r-t){
			l--;
		}else{
			l--;  r++;
		}
	}
	cout<<(long long)ans;
}

