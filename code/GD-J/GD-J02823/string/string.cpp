#include<bits/stdc++.h>
using namespace std;
int n,a[100000],cnt;
string b[1000000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int c=1;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	int i=1,j=n,mid=(1+n)/2;
	while(i<=mid&&j>=mid&&i!=j){
		if(a[i]==0){
			i+=1;
		}else if(a[j]==0){
			j-=1;
		}
		if(b[i]!=b[j])cnt++;
		a[i]--;
		a[j]--;
	}
	cout<<cnt;
	return 0;
}
