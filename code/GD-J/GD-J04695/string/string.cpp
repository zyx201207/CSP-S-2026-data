#include<bits/stdc++.h>
using namespace std;
long long a[100005],ans,n;
char c[100005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	long long h=1,t=n;
	while(h<t){
		if(a[h]>a[t]){
			if(c[h]==c[t]){
				a[h]-=a[t];
				t--;
			}
			else{
				a[h]-=a[t];
				ans+=a[t];
				t--;
			}
		}
		else if(a[h]<a[t]){
			if(c[h]==c[t]){
				a[t]-=a[h];
				h++;
			}
			else{
				a[t]-=a[h];
				ans+=a[h];
				h++;
			}
		}
		else{
			if(c[h]!=c[t]){
				ans+=a[h];
				h++;
				t--;
			}
			else{
				h++;
				t--;
			}
		}
	}
	cout<<ans;
	return 0;
}
