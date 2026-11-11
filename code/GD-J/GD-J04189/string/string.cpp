#include<bits/stdc++.h>
using namespace std;
int n;
int a[200005];
char c[200005];
long long ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int h=1,t=n;
	while(h<=t){
		if(c[h]==c[t]){
			if(a[h]>a[t]){
				a[h]-=a[t];
				t--;
			}
			else if(a[h]<a[t]){
				a[t]-=a[h];
				h++;
			}
			else{
				h++;
				t--;
			}
		}
		else{
			if(a[h]<a[t]){
				ans+=a[h];
				a[t]-=a[h];
				h++;
			}
			else if(a[h]>a[t]){
				ans+=a[t];
				a[h]-=a[t];
				t--;
			}
			else{
				ans+=a[h];
				h++,t--;
			}
		}
	}
	cout<<ans;
	return 0;
}
