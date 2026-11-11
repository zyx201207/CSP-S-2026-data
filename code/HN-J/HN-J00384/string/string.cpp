#include<iostream>
using namespace std;
long long a[200005];
int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
	long long x;
	string s;
	char y;
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		cin>>x>>y;
		for(int j=1;j<=x;j++)
		{
			s+=y;
		}
	} 
	long long ans=0,l=0,r=n;
	while(l<=r){
		if(s[l]!=s[r]){
			ans++;
		}
		l++;
		r--;
	}
	printf("%d",ans);
fclose(stdin);
fclose(stdout);
	return 0;
}
