#include<bits/stdc++.h>
using namespace std;
int n,m;
int s[20005],ans[20005];
string a[20005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	while(n--)cin>>s[n];
	for(int i=0;i<n;i++)
		while(s[i]){
			a[i]+=s[i]%2+'0';
			s[i]/=2;
		}
	for(int i=n;i>=0;i--)s[i]+=(a[i]-'0')*pow(10,i);
	for(int i=0;i<n;i++)for(int j=0;j<i;j++)ans[i+j]=a[i]&a[j];
	for(int i=0;i<n;i++)for(int j=0;j<i;j++)if(a[i]<=a[j])a[i]=0;
	for(int i=0;i<200000;i++)if(a[i]>0){cout<<a[i];
	return 0;}
	fclose(stdin);
	fclose(stdout);
}

