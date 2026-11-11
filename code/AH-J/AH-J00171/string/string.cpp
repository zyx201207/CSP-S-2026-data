#include<bits/stdc++.h>
using namespace std;
struct node{
	long long a;
	char c;
}b[200100],d[200100];
long long a[200100];
char c[200100];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	int n;
	cin>>n;
	long long cnt=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		cnt+=a[i];
	}
	long long ans=0,cnt1=0,l1=0,l2=0;
	for(int i=1;i<=n;i++){
		cnt1+=a[i];
		b[i].c=c[i];
		if(cnt1>=cnt/2){
			b[i].a=(cnt/2)-cnt1+a[i];
			l1=i;
			break;
		}
		b[i].a=a[i];
	}
	cnt1=cnt;
	for(int i=n;i>=1;i--){
		cnt1-=a[i];
		d[n-i+1].c=c[i];
		if(cnt1<=cnt-cnt/2){
			d[n-i+1].a=a[i]-cnt+cnt/2+cnt1;
			l2=n-i+1;
			break;
			
		}
		d[n-i+1].a=a[i];
	}
	int l=1,r=1,ans1=b[l].a,ans2=d[r].a;
	while(l<=l1&&r<=l2){
		if(ans1>ans2){
			if(b[l].c!=d[r].c){
				ans+=ans2;
			}
			ans1-=ans2;
			r++;
			ans2=d[r].a;
		}else if(ans1<ans2){
			if(b[l].c!=d[r].c){
				ans+=ans1;
			}
			ans2-=ans1;
			l++;
			ans1=b[l].a;
		}else{
			if(b[l].c!=d[r].c){
				ans+=ans1;
			}
			r++;
			l++;
			ans2=d[r].a;
			ans1=b[l].a;
		}
	}
	cout<<ans;
	return 0;
}
