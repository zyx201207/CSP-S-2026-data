#include<bits/stdc++.h>

using namespace std;

long long n;
long long a[200010];long long sums=0;
char a1[200010]; bool f=0;
long long ans;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		cin >> a1[i];
		sums+=a[i];
	}
	for(int i=1;i<=n-1;i++){
		if(a1[i]!=a1[i+1]){
			f=1;
		}
	}
	if(f==0){
		cout << 0;
		return 0;
	}
	long long i=1,j=n;
	while(i<=j){
		if(a1[i]==a1[j]){
			if(a[i]>a[j]){
				a[i]-=a[j];
				j--;
			}
			else if(a[i]<a[j]){
				a[j]-=a[i];
				i++;
			}
			else if(a[i]=a[j]){
				i++;j--;
			}
		}
		else{
			ans+=min(a[i],a[j]);
			if(a[i]<=a[j]){
				a1[i]=a1[j];
			}
			else{
				a1[j]=a1[i];
			}
		}
	}
	cout << ans;
    return 0;
}
