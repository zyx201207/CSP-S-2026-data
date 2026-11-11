#include<bits/stdc++.h>
using namespace std;
char s[100010];
long long a[100010];
char a1[50080];
char a2[50080];
char a3[100010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	bool flag=true;
	long long n,sum=0,num=0;
	cin>>n;
	if(n==1){
		cout<<0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s[i];
		if(i==1){
			for(int j=1;j<=a[i];j++){
				a3[j]=s[i];
			}
		}
		else{
			for(int j=num+1;j<=num+a[i];j++){
				a3[j]=s[i];
			}
		}
		num+=a[i];
		if(i>1 && s[i]!=s[i-1]){
			flag=false;
		}
	}
	if(flag==false){
		if(n%2==1){
			long long mid=(num+1)/2;
			for(int i=1;i<mid;i++){
				a1[i]=a3[i];
			}
			for(int i=1;i<mid;i++){
				a2[i]=a3[num-i+1];
			}
			for(int i=1;i<mid;i++){
				if(a1[i] != a2[i]){
					sum++;
				}
			}
		}
		else{
			long long mid=num/2;
			for(int i=1;i<=mid;i++){
				a1[i]=a3[i];
			}
			for(int i=1;i<=mid;i++){
				a2[i]=a3[num-i+1];
			}
			for(int i=1;i<=mid;i++){
				if(a1[i] != a2[i]){
					sum++;
				}
			}
		
	}
	else{
		cout<<0;
		return 0;
	}
	cout<<sum;
	return 0;
}
