#include<bits/stdc++.h>
using namespace std;
int n;
char s[200005];
long long a[200005]={1};
char c[200005];
int f=1;
int flag=0;
int sum;
int main(){
//	freopen("string.in","r",stdin);
//	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s[i];
		sum+=a[i]; 
		for(int i=a[i-1];i<=a[i-1]+a[i];i++){
			s[i]=c[i];
		}
	}
	for(int i=1;i<=sum;i++)
		cout<<s[i];
//	int ans=sum;
//	if(sum%2==0) sum/=2;
//	else sum=sum/2+1;
//	for(int i=ans;i>=sum;i--){
//		if(s[f]!=s[i])
//			flag++;
//		f++;
//	}
//	cout<<flag;
	return 0;
}
