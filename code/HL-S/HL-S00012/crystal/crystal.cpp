#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[10005];
int s[290000];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	int c=0;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			s[c]=a[j]-a[i];
			c++;
		}
	}
	sort(s,s+c);
	int sum=0;
	for(int i=0;i<c;i++){
		if(m>=s[i]){
			m-=s[i];
			sum++;
		}else{
			cout<<sum;
			return 0;
		}
	}
	
	return 0;
}