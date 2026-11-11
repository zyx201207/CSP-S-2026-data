#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5+10;
long long a[N];
long long num;
int l=-1,r=-1;
void find_max(int n){
	int temp=1,aans=1,index=1;
	for(int i=1;i<=n;i++){
		if(a[i] != a[i+1]){
			if(temp > aans){
				l = index;
				r = i;
			}
			aans = max(temp,aans);
			index = i+1;
		}
	}
}
bool cmp(int a,int b){
	return a<=b;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin >> n >> m;
	for(long long i=1;i<=n;i++)
		cin >> a[i];
	sort(a+1,a+n+1,cmp);
	
	find_max(n);
	bool flg = false;
	if(l==-1&&r==-1)flg=true;
	
	if(flg){
		int ans=1;
		for(int i=n;i>1;i--){
			int m1=m,temp=1;
			for(int j=i;j>1;j--){
				if(m1 - (a[j]-a[j-1])*(temp) < 0)break;
				m1-=(a[j]-a[j-1])*temp;
				temp+=1;
			}
			ans = max(temp,ans);
		}
		cout << ans << '\n';
	}
	else{
		if(r+1>n){
			int ans = r-l+1;
			for(int i=l;i>=1;i--)
			{
				if(m - (a[i]-a[i-1]) < 0)break;
				m-=(a[i]-a[i-1]);
				a[i-1] = a[i];
				ans+=1;
			}
			cout << ans << '\n';
			return 0;
		}
		else if(l-1<1){
			int ans = r-l+1;
			for(int i=r;i<=n;i++)
			{
				if(m - (a[i+1]-a[i]) < 0)break;
				m-=(a[i+1]-a[i]);
				a[i] = a[i+1];
				ans+=1;
			}
			cout << ans << '\n';
			return 0;
		}
		else{
			int ans = r-l+1;
			for(int i=l,j=r;i>=1,j<=n;){
				if(a[i] - a[i-1] < a[j+1] -a[j]){
					if(m - (a[i]-a[i-1]) < 0)break;
					m-=(a[i] - a[i-1]);
					a[i-1] = a[i];
					ans+=1;
					i-=1;
				}
				else{
					if(m - (a[j+1]-a[j]) < 0)break;
					m-=(a[j+1] -a[j]);
					a[j] = a[j+1];
					ans+=1;
					j+=1;
				}
			}
			cout << ans << '\n';
			return 0;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
