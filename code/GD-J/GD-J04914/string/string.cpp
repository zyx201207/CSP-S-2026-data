#include<bits/stdc++.h>
#define int long long
using namespace std;
const int hxy=3e7;
int a[hxy],b[hxy],n,m,j,k,l,d[hxy],x,y,ans,sum,cnt,g,h,ansr,r;
char c[hxy];
main(){
	freopen("string.in","r",stdin);
	freopen("string.ans","w",stdout);
	int t;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		sum+=a[i];
	}
	if(sum%2==1)k=sum/2+1;
	else k=sum/2;
	for(int i=1;i<=n;i++){
		if(cnt+a[i]>k){
			x=i-1;
			break;
		}
		cnt+=a[i];
	}
	if(cnt==k)
	y=x+1;
	else y=x+2; 
	g=k-cnt;
	h=sum-cnt-a[x+1];
	int uu=cnt+a[x+1]-k;
	ansr=abs(g-uu);
	if(g<h){
		x++;
		a[x]=ansr;
	}
	else if(g>h){
		y--;
		a[y]=ansr;
	}
	l=1;
	r=n;
	while(l<=r){
		if(c[l]!=c[r]){
			if(a[l]>a[r]){
				a[l]-=a[r];
				ans+=a[r];
				r--;
			}
			else if(a[l]<a[r]){
				a[r]-=a[l];
				ans+=a[l];
				l++;
			}
			else if(a[l]==a[r]){
				r--;
				l++;
				ans+=a[l];
			} 
		}
		else{
			if(a[l]>a[r]){
				a[l]-=a[r];
				r--;
			}
			else if(a[l]<a[r]){
				a[r]-=a[l];
				l++;
			}
			else if(a[l]==a[r]){
				r--;
				l++;
			} 
		}
	}
	cout<<ans;
}
