#include<bits/stdc++.h>
using namespace std;
int n,n1,a[200010],a1,a2;
long long ans;
char c[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		cin>>c[i];
	}
	a1=1;
	a2=n;
	while(a1<a2){
		if(c[a1]==c[a2]){
			if(a[a1]<a[a2]){a[a2]-=a[a1];a1++;}
			else{if(a[a1]==a[a2]){a1++;a2--;}
			else if(a[a1]>a[a2]){a[a1]-=a[a2];a2--;}}
		}
		if(c[a1]!=c[a2]){
			if(a[a1]<a[a2]){

				ans+=a[a1];
				a[a2]-=a[a1];
				a1++;
			}
			else{
			if(a[a1]==a[a2]){
				ans+=a[a1];
				a1++;a2--;
			}
			else{
			if(a[a1]>a[a2]){
				ans+=a[a2];
				a[a1]-=a[a2];
				a2--;
			}
			}
			}
		}
	}
	printf("%lld",ans);
}
