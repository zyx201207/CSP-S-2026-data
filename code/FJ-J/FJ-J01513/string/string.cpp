#include<iostream>
using namespace std;
long long n,ans;
struct xx{
	int x;
	char c;
}a[200010];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].c;
	}
	int l=1,r=n;
	while(l<=r){
		if(a[l].x<a[r].x){
			if(a[l].c!=a[r].c){
				ans+=(long long)a[l].x;
			}
			a[r].x-=a[l].x;
			l++;
		}else if(a[l].x>a[r].x){
			if(a[l].c!=a[r].c){
				ans+=(long long)a[r].x;
			}
			a[l].x-=a[r].x;
			r--;
		}else{
			if(a[l].c!=a[r].c){
				ans+=(long long)a[r].x;
			}
			r--;l++;
		}
	}
	cout<<ans;
	return 0;
}
