#include<bits/stdc++.h>
using namespace std;
long long n,cnt=0,s=0,z=0,apt=0,brr[1000001],i=0,l;
char arr[1000001];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int j=1,j_=n;
	for(int i=1;i<=n;i++){
		cin>>brr[i]>>arr[i];
		cnt+=brr[i];
	}
	for(i=1;i<=cnt/2;i++){
		s++;
		if(s>brr[j]){
			s-=brr[j];
			j++;
		}
		z++;
		if(z>brr[j_]){
			z-=brr[j_];
			j_--;
		}
		if(arr[j]!=arr[j_]){
		apt++;
		l=min(brr[j]-s,brr[j_]-z);
		i+=l;
		apt+=l;
		s+=l;
		z+=l;
}
		else if(arr[j]==arr[j_]){
		l=min(brr[j]-s,brr[j_]-z);
		i+=l;
		s+=l;
		z+=l;
		}
	}
	cout<<apt;
	return 0;
}
