#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,a[200005],t,s,ans,t2;
char b[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i = 1;i <= n;i++){
		scanf("%lld %c",&a[i],&b[i]);
		s+=a[i];
	}
	for(int i = 1;i <= n;i++){
		t+=a[i];
		if(t==s/2){
			t=i;
			break;
		}
		if(t>s/2){
			for(int j = n+1;j >= i+2;j--){
				a[j]=a[j-1];
				b[j]=b[j-1];
			}
			b[i+1]=b[i];
			a[i+1]=t-s/2;
			a[i]-=a[i+1];
			n++;
			t=i;
			break;
		}
	}
	t2=n;
	for(int i = 1;i <= t;i++){
		if(a[i]!=a[t2]||b[i]!=b[t2]){
			s=0;
			while(s<a[i]){
				if(b[i]==b[t2]){
					if(a[t2]>a[i]-s){
						a[t2]-=(a[i]-s);
						s=a[i];
					}else{
						s+=a[t2];
						t2--;
					}
				}else{
					if(a[t2]>a[i]-s){
						a[t2]-=(a[i]-s);
						ans+=(a[i]-s);
						s=a[i];
					}else{
						s+=a[t2];
						ans+=a[t2];
						t2--;
					}
				}
			}
		}else{
			t2--; 
		}
	}
	cout<<ans;
	return 0;
}
