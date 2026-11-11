#include<bits/stdc++.h>
using namespace std;
const int N=2e6;
int n,x,ans,cnt;
long long s;
char a[N],b[N],y;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>x>>y;
		for(int j=ans;j<=ans+x-1;j++){
			a[j]=y;
		}
		ans+=x;
	}
	int sum=0;
	for(int i=ans-1;i>=0;i--){
		b[sum]=a[i];
		sum++;
	}
	for(int i=0;i<ans;i++){
		if(a[i]!=b[i]){
			cnt++;
			a[ans-1-i]=a[i];
		}
	}
	cout<<cnt;
	return 0;
} 
