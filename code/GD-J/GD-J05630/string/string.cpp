#include<bits/stdc++.h>
using namespace std;
long long n,a[200001],ans,front=1,last;
char c[200001];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		last++;
	}
	while(front<last){
		if(a[front]==a[last]){
			if(c[front]!=c[last]) ans+=a[front];
			front++;
			last--;
		}
		else if(a[front]>a[last]){
			a[front]-=a[last];
			if(c[front]!=c[last]){
				ans+=a[last];
			}
			last--;
		}
		else{
			a[last]-=a[front];
			if(c[front]!=c[last]){
				ans+=a[front];
			}
			front++;
		}
	}
	cout<<ans;
	return 0;
} 
