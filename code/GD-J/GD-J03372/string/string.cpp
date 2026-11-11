#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define LL long long
#define inf 0x3f
#define Inf 0x3f3f3f3f3f3f3f3f
const int N=2e5+5;
int n;
ll a[N];
char c[N];
ll sum,cur;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cin>>c[i];
	}
	for(int i=1,j=n;i<j;){
		if(c[i]!=c[j]){
			if(a[i]>a[j]) {
				sum+=a[j];
				a[i]-=a[j];
				j--;
			}
			else {
				sum+=a[i];
				a[j]-=a[i];
				i++;
			}
		}
		else{
			if(a[i]>a[j]){
				a[i]-=a[j];
				j--;
			}	
			else{
				a[j]-=a[i];
				i++;
			}
		}
	}
	cout<<sum;
	return 0;
}
