#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],s;
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i]>>c[i];
	int h=1,t=n;
	while(h<t){
		int k;
		k=min(a[h],a[t]);
		if(c[h]!=c[t])s+=k;
		a[h]-=k;
		a[t]-=k;
		if(a[h]==a[t]){
			h++;
			t--;
		}
		else{
			if(a[h]>a[t])t--;
			else h++;
		}
	}
	cout<<s;
	return 0;
}
