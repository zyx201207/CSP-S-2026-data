#include<bits/stdc++.h>
using namespace std;
long long n,num[100005];
string a[100005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>num[i]>>a[i];
	}
	long long l=1,r=n,cnt=0;
	while(l<r){
		if(num[l]==num[r]){
			if(a[l]!=a[r]) cnt+=num[r];
			l++;
			r--;
		}
		else if(num[l]!=num[r]){
			if(num[l]>num[r]){
				num[l]-=num[r]; 
				if(a[l]!=a[r]){ 
					cnt+=num[r];
				}
				r--;
			}
			else{ 
				num[r]-=num[l];
				if(a[l]!=a[r]){
					cnt+=num[l];
				}
				l++;
			}
		}
	}
	cout<<cnt;
	return 0;
}
