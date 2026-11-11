#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int c=0;
	int n;
	cin>>n;
	char x[1000000001];
	int a[1000000001];
	for(int i=0;i<n;++i){
		cin>>a[i]>>x[i];
	}
	for(int i=0;i<n;++i){
		if(x[i]==x[n-1-i]){
			c+=1;
		}else{
		    c=0;	
		}
	}
	if(c==n/2)cout<<"0";
	for(int i=0;i<n;++i){
		if(x[i]!=x[n-i]){
			if(a[i]==a[n-1-i])
			    c+=a[i];
			else if(a[i]>a[n-1-i])
			    c+=a[i]-a[n-1-i];
			else c+=a[n-1-i]-a[i];
		}
	}
	cout<<c;
	fclose(stdin);fclose(stdout);
	return 0;
}
