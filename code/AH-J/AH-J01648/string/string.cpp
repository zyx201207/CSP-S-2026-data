#include<bits/stdc++.h>
using namespace std;
int n,m,i,j;
long long sum;
bool f;
int a[200005];
char b[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	i=1,j=n;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>b[i];
	while(i<j){
		if(b[i]!=b[j]) f=1;
		else f=0;
		if(a[i]<a[j]){
			a[j]-=a[i];
			if(f) sum+=a[i];
			i++;
		}
		else if(a[i]>a[j]){
			a[i]-=a[j];
			if(f) sum+=a[j];
			j--;
		}
		else{
			if(f) sum+=a[i];
			i++,j--;
		}
	}
	cout<<sum<<'\n';
	return 0;
}

