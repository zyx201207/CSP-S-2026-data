#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;
int n;
ll a[N];
char c[N];
ll ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%lld ",&a[i]);
		c[i]=getchar();
	}
	int tnt=n;
	for(int i=1;i<=n;i++){
		while(a[i]>0){
			if(i==tnt){
				break;
			}
			if(a[i]>=a[tnt]){
				if(c[i]!=c[tnt])ans=ans+a[tnt];
				a[i]-=a[tnt];a[tnt]=0;tnt--;
			}
			else{
				if(c[i]!=c[tnt])ans=ans+a[i];
				a[tnt]-=a[i];a[i]=0;
			}
		}
	}
	cout<<ans;
	return 0;
} 
