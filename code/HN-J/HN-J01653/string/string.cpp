#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
ll n,a[200001],ans;
char c[200001];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;i++) cin>>a[i]>>c[i];
	ll i=1,j=n,num1=a[i],num2=a[j];
	while(i<=j){
		if(c[i]==c[j]){
			if(num1>num2){
				num1-=num2;
				j--;
				num2=a[j];
			}
			else if(num1==num2){
				i++;
				j--;
				num1=a[i];
				num2=a[j];
			}
			else{
				num2-=num1;
				i++;
				num1=a[i];
			}
		}
		else{
			if(num1>num2){
				num1-=num2;
				ans+=num2;
				j--;
				num2=a[j];
			}
			else if(num1==num2){
				ans+=num1;
				i++;
				j--;
				num1=a[i];
				num2=a[j];
			}
			else{
				num2-=num1;
				ans+=num1;
				i++;
				num1=a[i];
			}
		}
	}
	cout<<ans;
	return 0;
}

