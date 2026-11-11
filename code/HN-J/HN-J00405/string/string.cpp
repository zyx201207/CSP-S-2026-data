#include<bits/stdc++.h>
using namespace std;
char a;
long long int n,m,len,arr[200001];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long int i=0;i<n;i++){
		cin>>m>>a;
		for(long long int j=len;j<len+m;j++){
			arr[j]=a-'a';
		}
		len+=m;
	}
	for(long long int i=0;i<len;i++)cout<<arr[i];
	cout<<endl; 
	m=0;
	for(long long int i=0;i<len/2;i++){
		if(arr[i]!=arr[len-i-1])m++;
	}
	cout<<m;
	return 0;
} 
