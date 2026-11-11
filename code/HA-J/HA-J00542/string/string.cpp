#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,a[110370],ans=0,num=1;
	char c[110370];
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	while(num!=n){
		if(c[num]!=c[n]){
			ans+=min(a[num],a[n]);
		}
		if(a[num]>a[n]){
			a[num]-=a[n];
			n--;
		}
		else if(a[num]<a[n]){
			a[n]-=a[num];
			num++;
		}
		else{
			if(n-num==1)break;
			num++;
			n--;
		}
	}
	cout<<ans;
	return 0;
}
