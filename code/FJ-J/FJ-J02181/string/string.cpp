#include<bits/stdc++.h>
using namespace std;
struct qi{
	int num;
	char zf;
};
qi a[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long ans=0;
	int n,l=1,r,pp;
	cin>>n;
	r=n;
	for(int i=1;i<=n;i++){
		cin>>a[i].num>>a[i].zf;
	}
	while(r-l>0){
		if(a[l].zf==a[r].zf){
			pp=0;
		}
		else{
			pp=1;
		}
		if(a[l].num>a[r].num){
            ans+=a[r].num*pp;
			a[l].num-=a[r].num;
			r-=1;
		}
		else{
			if(a[l].num<a[r].num){
				ans+=a[l].num*pp;
				a[r].num-=a[l].num;
				l+=1;
			}
			else{
				ans+=a[l].num*pp;
				l+=1;
				r-=1;
			}
		}
	}
	cout<<ans;
	return 0;
} 
