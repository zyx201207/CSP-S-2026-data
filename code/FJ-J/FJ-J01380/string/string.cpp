#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,a[N],b=0;
long long cnt=0,cn=0,sum=0;
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		cnt+=a[i];
	}
	for(int i=1;i<=n;i++){
		cn+=a[i];
		if(cn>cnt/2){
			b=i;
			break;
		}
	}
	int l=1,r=n;
	while(l<=b && r>=b){
		if(c[l]==c[r]){ 
			if(a[l]<=a[r]){
				a[r]-=a[l];
				l++;
			}
			else{
				a[l]-=a[r];
				r--;
			}
		}
		else{
			if(a[l]<=a[r]){
				sum+=a[l];
				a[r]-=a[l];
				l++;
			}
			else{
				sum+=a[r];
				a[l]-=a[r];
				r--;
			}
		}
	}
	cout<<sum;
	return 0;
}
