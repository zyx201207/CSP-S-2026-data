#include <bits/stdc++.h>
using namespace std;
int n,m;
long long a[500005],sum=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
	}
	sum+=m;
	sort(a+1,a+1+n);
	int rs=n;
	int mid=sum/rs;
	while(mid<a[rs]){
		sum-=a[rs];
		rs--;
		mid=sum/rs;
	}
	cout<<rs;
	return 0;
}

/*
#include <bits/stdc++.h>
using namespace std;
int n,m;
long long a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);//^
	int de,now=0;
	while(m>=0)
	{
		now++;
		de=a[now+1]-a[now];
		m-=(de*now);
	}
	cout<<now;
	return 0;
}
*/
