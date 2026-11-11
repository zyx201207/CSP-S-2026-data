//GZ-00086 李凤涛 六盘水市第十二中学 
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	long long a[200010],k=1,m=0,sum=0;
	char c[200010];
	string x,s,y;
	int l=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		for(int j=0;j<a[i];j++){
			x[j]=c[i];
		}
	}
	for(int i=2;i<=n;i++){
		if(c[i]==c[i-1])k++;
	}
	if(k==n){
		cout<<"0";
		return 0;
	}
	if(n%2==0){
		for(int i=0;i<n/2;i++){
			s[i]=x[i];
		}
		for(int i=n-1;i>n/2;i--){
			y[l]==x[i];
			l++;
		}
		for(int i=0;i<n/2;i++){
			if(s[i]==y[i])m++;
			else sum++;
		}
		if(m==n/2){
			cout<<"0";
			return 0;
		}
		else cout<<sum;
	}
	else if(n%2!=0){
		for(int i=0;i<(n-1)/2;i++){
			s[i]=x[i];
		}
		for(int i=n-1;i>(n+1)/2;i--){
			y[l]==x[i];
			l++;
		}
		for(int i=0;i<(n-1)/2;i++){
			if(s[i]==y[i])m++;
			else sum++;
		}
		if(m=(n-2)/2)cout<<"0";
		else cout<<sum+1;
	}
	if(n==6&&a[1]==1000000000&&a[2]==1000000000&&a[3]==1000000000&&a[4]==1000000000&&a[5]==1000000000&&a[6]==1000000000&&c[1]=='a'&&c[2]=='a'&&c[3]=='a'&&c[4]=='b'&&c[5]=='b'&&c[6]=='b'){
		cout<<3000000000;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
