//t1
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int a[550000];
int b[550000];
//priority_queue<int> aa;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ll n,m;
	cin>>n>>m;
	//cout<<n<<m;
	for(int i=1;i<=n;i++){
		scanf("%d",a+i);
	}
		//cout<<1;
	//if(n<=50000)
	/*for(int i=1;i<=n;i++){
		cout<<a[i];
	}*/
	sort(a+1,a+n+1);
	//cout<<1;
	//cout<<n;
	a[0]=a[1];
	ll l=1,r=1,need=0,maxx=0;;
	for(r=1;r<=n;r++){
		need+=(a[r]-a[r-1])*(r-l);
		while(need>m&&r>=l){
			need-=a[r]-a[l];
			l++;
		}
		if(need<=m)
		maxx=max(maxx,r-l+1);
		//cout<<need<<" "<<l<<" "<<r<<" "<<maxx<<"\n";
		//cout<<(r>n)<<"\n";
		if(r>n)
		break;
	}
	//cout<<n;
	//int s=1,e=1;
	/*for(int i=1;i<=n;i++){
		//cout<<a[i];
		//b[e++]=i;
		while(a[i]>=a[b[e]]&&e>=s)e--;
		b[++e]=i;
		if(b[s]<i-5) s++;
		
		cout<<a[b[s]]<<" "<<b[s]<<"\n";
	}*/
	cout<<maxx;
	return 0;
}/* 5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/
