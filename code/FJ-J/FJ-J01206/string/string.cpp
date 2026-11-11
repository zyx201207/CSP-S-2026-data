#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long l=0,cnt=0,n,a[200001];
	string s;
	char c[200001];
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
		l+=a[i];
	}
	long long m=l/2,sum=0;
	for(int i=0;i<n;i++){
		sum+=a[i];
		if(sum>=m){
			m=i;
			break;
		}
	}
	for(int i=0,j=n-1;i<=m&&j>=m;){
		if(i==j){
			break;
		}
	 	if(a[i]>a[j]){
	 		if(c[i]!=c[j]){
	 			cnt+=a[j];
			}
			a[i]-=a[j];
			j--;
		}else if(a[i]<a[j]){
			if(c[i]!=c[j]){
	 			cnt+=a[i];
			}
			a[j]-=a[i];
			i++;
		}else{
			if(c[i]!=c[j]){
				cnt+=a[i];
			}
			i++;
			j--;
		}
	}
	cout<<cnt;
	return 0;
} 
