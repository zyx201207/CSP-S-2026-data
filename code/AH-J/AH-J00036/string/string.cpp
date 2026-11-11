#include<bits/stdc++.h>
using namespace std;
char a[3];
int b[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	bool f=true;
	char last;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>b[i]>>a[i];
		if(i==1)last=a[i];
		if(a[i]!=last)f=false;
		last=a[i];
	}
	if(f){
		cout<<0;
		return 0;
	}
	long long ans=0;
	for(int i=1,j=n;i<=j;){
		if(a[i]!=a[j]){
			ans+=min(b[i],b[j]);
		}
		if(b[i]>b[j]){
			b[i]-=b[j],b[j]=0;
			j--;
		}
		else if(b[j]>b[i]){
			b[j]-=b[i],b[i]=0;
			i++;
		}
		else{
			b[i]=b[j]=0;
			i++,j--;
		}
	}
	cout<<ans;

	return 0;
}

