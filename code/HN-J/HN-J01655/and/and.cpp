#include<bits/stdc++.h>
using namespace std;
long long n,ans,a[200009],m;
bool cmp(long long a,long long b){
	return a<b;
}
void type_and(long long cnt,long long a){
	int i=1,t[1009],d[1009];
	while(cnt!=0){
		t[i]=cnt%2;
		cnt/=2;
		d[i]=a%2;
		a/=2;
		i++;
	}
	i--;
	for(int j=1;j<=i;j++){
		ans+=(t[i]&&d[i])*pow(2,i);
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n,cmp);
	int h=1;
	while(ans==0||h<=n){
		if(a[h]%2==0)ans=a[h];
		h++;
	}
	if(ans==0)ans=a[1];
	for(int i=2;i<=m;i++)type_and(ans,a[i]); 
	cout<<ans;
	return 0;
}
