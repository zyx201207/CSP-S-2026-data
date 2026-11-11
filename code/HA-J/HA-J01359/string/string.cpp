#include<bits/stdc++.h>
using namespace std;

long long n,a[200005],c[200005],cnt,mid,ans;
struct qj{
	long long l,r,ff;
}q[200005],q2[200005],q3[200005];
long long len,len2;

bool cmp(qj a,qj b){
	return a.l<b.l;
}

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++){
		char x;
		cin>>a[i]>>x;
		c[i]=x-'a';
		cnt+=a[i];
	}
	
	ans=(cnt+1)/2;
	mid=(cnt+1)/2;
	long long pd=-1,lj=1;
	for (int i=1;i<=n;i++){
		if(pd!=c[i]){
			pd=c[i];
			len++;
			q[len].l=lj;
		}
		lj+=a[i];
		q[len].ff=c[i];
		q[len].r=lj-1;
	}
	long long bg=-1;
	int f=0;
	for (int i=1;i<=len;i++){
		if(q[i].r<=mid){
			q2[++len2]=q[i];
			bg=i+1;
			q2[len2].r=mid-q[len2].l+(cnt-mid+1);
			q2[len2].l=mid-q[len2].r+(cnt-mid+1);
		}else if(q[i].l<=mid){
			f=1;
			q2[++len2]=q[i];
			q2[len2].r=mid;
			q2[len2].r=mid-q[len2].l+(cnt-mid+1);
			q2[len2].l=mid-mid+(cnt-mid+1);
			q[i].l=(cnt-mid+1);
		}else break;
	}
	sort(q2+1,q2+len2+1,cmp);
	for (int i=bg,j=1;j<=len2;j++){
		for (;i<=len && q[i].r<=q2[j].r;i++){//完全包含
			if(q2[j].ff==q[i].ff){
				ans-=(q[i].r-q[i].l+1);
			}
		}
		if(q[i].l<=q2[j].r && i<=len && j<=len2){//有交集
			if(q[i].ff==q2[j].ff){
				ans-=(q2[j].r-q[i].l+1);
			}
			q[i].l=q2[j].r+1;
		}
	}
	
	cout<<ans;
	
	return 0;
}
