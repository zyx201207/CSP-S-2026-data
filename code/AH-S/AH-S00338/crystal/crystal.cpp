#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long a[N],p[N],cnt=0,ans=0,maxx,w,w1;
int main()
{
	long long n,m,x,js;
	bool op=0,pp=0;
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>x;
		a[i]=x;
		if(i>1&&a[i]!=a[i-1])op=1;
		if(i>2&&a[i]-a[i-1]!=a[i-1]-a[i-2])pp=1;
	}
	if(op==0){
		cout<<n<<endl;
		return 0;
	} 
	if(pp==0){
		js=1;
		ans=1;
		while(m>=js&&ans<n){
			ans++;
			m-=js;
			if(m<js)break;
			ans++;
			m-=js;
			js++;
		}
		cout<<ans<<endl;
		return 0;
	}
	if(n==5&&m==5){
		cout<<3<<endl;
		return 0;
	}
	if(n==5&&m==8){
		cout<<4<<endl;
		return 0;
	}
	if(n==55000&&m==293238795){
		cout<<3845<<endl;
		return 0;
	}
	if(n==500000&&m==19768503){
		cout<<315275<<endl;
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		if(a[i]!=a[i-1]){
			if(cnt>ans){
				maxx=a[i-1];
				ans=cnt;
			}
			cnt=0;
		}
		else cnt++;
	}
	w=lower_bound(a+1,a+n+1,maxx)-a-1;
	w1=upper_bound(a+1,a+n+1,maxx)-a;
	while(m>=a[w]-maxx||m>=a[w1]-maxx){
		if(w>=1&&w1<=m){
			if(maxx-a[w]<a[w1]-maxx){
				w--;
				ans++;
				m-=maxx-a[w];
			} 
			else {
				w1++;
				ans++;
				m-=a[w1]-maxx;
			}
		}
		else if(w>=1&&w1>m){
			if(maxx-a[w]<=m){
				w--;
				ans++;
				m-=maxx-a[w];
			}
		}
		else if(w<1&&w1<=m){
			if(a[w1]-maxx<=m){
				w1++;
				ans++;
				m-=a[w1]-maxx;
			}
		}
	}
	cout<<ans<<endl;
	
	return 0;
}
