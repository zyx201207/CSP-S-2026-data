#include<bits/stdc++.h>
using namespace std;
long long t,x,cnt=1,ans=0;
char c;
struct sb{
	long long n;
	char c1;
}a[2000005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>x>>c;
		a[cnt].n=x;
		a[cnt++].c1=c;
	}
	int l=1,r=cnt;
	while(l<=r){
		if(a[l].c1==a[r].c1){
			if(a[l].n==a[r].n){
				l++;
				r--;
			}else{
				if(a[l].n>a[r].n){
					a[l].n-=a[r].n;
					r--;
				}else{
					a[r].n-=a[l].n;
					l++;
				}
			}
		} 
		else{
			if(a[l].n==a[r].n){
				ans+=a[l].n;
				l++;
				r--;
			}else{
				if(a[l].n>a[r].n){
					a[l].n-=a[r].n;
					ans+=a[r].n;
					r--;
				}else{
					a[r].n-=a[l].n;
					ans+=a[l].n;
					l++;
				}
			}
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
