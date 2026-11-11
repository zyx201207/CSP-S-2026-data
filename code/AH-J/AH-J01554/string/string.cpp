#include<bits/stdc++.h>
using namespace std;
long long a[200005],w[200005];
long long n,x,l=0,ans=0;
char y;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int k=n;
	while(n--){
		cin>>x>>y;
		a[k-n]=x;
		w[k-n]=y;
		l+=x;
	}
	int i=1;
	while(k!=i){
		if(w[i]!=w[k]){
			if(a[i]<=a[k]){
				ans+=a[i];
				a[k]-=a[i];
				i++;
			}
			else{
				ans+=a[k];
				a[i]-=a[k];
				k--;
			}
		}
		else{
			if(a[i]<=a[k]){
				a[k]-=a[i];
				i++;
			}
			else{
				a[i]-=a[k];
				k--;
			}
		}				
	}
	cout<<ans;
	return 0;
}

