#include<bits/stdc++.h>
using namespace std;
int n,ans=0;
long long a[500005],f[500005];
long long m;
int sum=1;
/*int read(){
	int x=0,f=-1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch){
		x=x*10+ch;
		ch=getchar();
	}
	return x*f;
}*/
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		f[i]=f[i-1]+(i-sum)*(a[i]-a[i-1]);
		while(f[i]>m){
			f[i]-=(a[i]-a[sum++]);
		}
		ans=max(ans,i-sum+1);		
	}
	cout<<ans;

} 
