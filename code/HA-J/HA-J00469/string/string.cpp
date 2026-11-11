#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
int a[maxn];
char c[maxn];
long long sum;
int n;
long long x;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		sum+=a[i];
	}
	int j1=1,j2=n;
	long long ans1=a[1],ans2=sum-a[n]+1;
	for(long long i=1;i<=sum/2;i++){
		if(i>ans1){
			j1++;
			ans1+=a[j1];
		}
		if((sum-i+1)<ans2){
			j2--;
			ans2-=a[j2];
		}
		if(c[j1]!=c[j2]) x++;
	}
	cout<<x;
	return 0;
}
/*#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
const int maxn=2e5+10;
int a[maxn];
char c[maxn];
string L;
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c;
	}
	
	for(int i=1;i<=n/2;i++){
		if(c[i]==c[n-i+1]){
			if(a[i]>a[n-i+1]){
				int t=a[i]-a[n-i+1];
				if(c[i]==c[n-i]){
			}
		}
	}
	
	return 0;
	*/
