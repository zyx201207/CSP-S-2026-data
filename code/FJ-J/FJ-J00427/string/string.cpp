/*
I AK CSP!!!
I AK CSP!!!
I AK CSP!!!
*/
//100+100+55+48=303pts
//100pts
#include<bits/stdc++.h>
using namespace std;
char c[200005];
int a[200005];
int n;
long long ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cin>>c[i];
	}
	if(n==1){
		cout<<"0";
		return 0;
	}
	int i=1,j=n;
	while(i<j){
		if(c[i]!=c[j]){
			if(a[i]>a[j]){
				a[i]-=a[j];
				ans+=a[j];
				j--;
			}else if(a[j]>a[i]){
				a[j]-=a[i];
				ans+=a[i];
				i++;
			}else{
				ans+=a[i];
				j--;
				i++;
			}
		}else{
			if(a[i]>a[j]){
				a[i]-=a[j];
				j--;
			}else if(a[j]>a[i]){
				a[j]-=a[i];
				i++;
			}else{
				j--;
				i++;
			}
		}
	}
	cout<<ans;
	return 0;
}
/*
I AK CSP!!!
I AK CSP!!!
I AK CSP!!!
*/ 
/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
6
1923 a
3993 b
221 c
120 i
212 u
101 i
*/
