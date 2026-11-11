#include<bits/stdc++.h>
#define inc(i,l,r) for(int i=l;i<=r;++i)
#define dec(i,r,l) for(int i=r;i>=l;--i)
using namespace std;
const int M=3e5+10,N=5e5+10;
int a[N];
int b[N];
bool up=1;
int cnt[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	inc(i,1,n){
		cin>>a[i];
		if(i>1&&a[i]<a[i-1])up=0;
	}
	if(up){
		inc(i,1,m){
			int k=upper_bound(a+1,a+n+1,i)-a;
			if(a[k-1]!=i)cnt[i]=0;
			else cnt[i]=k-1;
		}
		inc(i,1,m){
			cout<<cnt[i]<<" ";
		}
		return 0;
	}
	int len=n;
	inc(i,1,n){
		inc(j,1,n)b[j]=a[j];
		len=n;
		for(int k=i;k<=n;k++){
			int j=i;
			for(;j<=len;j++){
				if(b[j]==a[k])break;
			}
			//cout<<j<<"\n";
			if(j<=len){
				len=j;
			}
			else b[++len]=a[k];
		}
		inc(g,1,m){
			int j=0;
			sort(b+i,b+len+1);
			j=lower_bound(b+i,b+len+1,g)-b;
			if(j<=len&&b[j]==g){
				cnt[g]++;
				//cout<<g<<" ";
			}
		}
		//cout<<"!";
	}
	inc(i,1,m){
		cout<<cnt[i]<<" ";
	}
}
