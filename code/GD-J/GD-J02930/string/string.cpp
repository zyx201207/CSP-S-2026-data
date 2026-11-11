#include<bits/stdc++.h>
using namespace std;
int a[222222];
char b[222222];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	long long i=0,j=n;
	long long iw=0,jw=a[n];
	long long ans=0;
	while(i+n-j+1<n){
		//cout<<'x';
		if(iw<jw){
			if(b[i+1]!=b[j]){
				//cout<<min(iw+a[i+1],jw)-iw<<' ';
				ans+=min(iw+a[i+1],jw)-iw;
			}
			i++;
			iw+=a[i];
		}else{
			if(b[j-1]!=b[i]){
				//cout<<min(iw,jw+a[j-1])-jw;
				ans+=min(iw,jw+a[j-1])-jw;
			}
			j--;
			jw+=a[j];
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
