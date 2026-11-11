#include<bits/stdc++.h>
using namespace std;
long long mm,m,n,k,maxn;
long long a[200005],book[200005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>mm;
	if(mm<=1000000000){
		for(int i=1;i<=n;i++){
			cin>>k;
			a[k+100000]++;
			book[k+100000]++;
		}
		for(int i=0;i<=200000;i++){
			if(a[i]!=0){
				m=mm;
				int t=i;
				while(m>=0&&t<=200003){
					m-=a[t];
					t++;
					a[t]+=a[t-1];
				}
				if(m<0){
					if(max(a[t]+m,a[t-1])>maxn)
						maxn=max(a[t]+m,a[t-1]);
				}
				else
					if(a[t]>maxn)
						maxn=a[t];
				for(int j=1;j<=t;j++)a[j]=book[j];
			}
		}
	}
	else{
		m=mm;
		for(int i=1;i<n;i++)cin>>k;
		long long k1,num=1;
		cin>>k1;
		long long cha=k1-k;
		while(m>=0){
			m-=num*cha;
			num++;
		}
		maxn=num-1;
	}
	cout<<maxn;
	return 0;
}
