#include<bits/stdc++.h>
using namespace std;
int a[200069];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	if(1==m){int maxn=-2<<30;
		for(int i=1;i<=n;i++){
			int c;
			cin>>c;
			maxn=max(maxn,c);
		}
		cout<<maxn;
		return 0;
	}
	if(2==m){int maxn=-(2<<30-1),maxnj=-2<<30;
		for(int i=1;i<=n;i++){
			int c;
	scanf("%d",c);
			if(c>maxn)maxn=c;
			else maxnj=max(maxnj,c);
		}
		cout<<1<<(maxn&maxnj);
		return 0;
	}
	if(n-1==m){int maxnj=2<<30,ans=maxnj-1;
		for(int i=1;i<=n;i++){
	scanf("%d",a[i]);
		}
		sort(a+1,a+1+n);
		ans=a[2];
		for(int i=3;i<=n;i++)ans&=a[i];
		cout<<ans; 
		return 0;
	}
	if(n==m){int maxnj=2<<30,ans=maxnj-1;
		for(int i=1;i<=n;i++){
	scanf("%d",a[i]);
		}
		sort(a+1,a+1+n);
		ans=a[1];
		for(int i=2;i<=n;i++)ans&=a[i];
		cout<<ans; 
		return 0;
	}
	return 0;
}
/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
4 2
3 15 12 12
*/
