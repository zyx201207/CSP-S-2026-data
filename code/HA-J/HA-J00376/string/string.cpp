#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,num[100010],r=0,l=0,cha=0,sum=0;
	char s[100010];
	cin>>n;
	for(long long i=0;i<n;i++){
		cin>>num[i]>>s[i];
		r++;
		cha+=num[i];
	}
	while(cha&&l<r){
		if(s[l]!=s[r]){
			if(num[l]>num[r]){
				num[l]-=num[r];
				cha-=num[r];
				sum+=num[r];
				r--;
			}else if(num[l]<num[r]){
				num[r]-=2*num[l];
				cha-=2*num[l];
				sum+=num[l];
				l++;
			}else{
				cha-=2*num[l];
				sum+=num[l];
				l++;
				r--;
			}
		}else{
			if(num[l]>num[r]){
				num[l]-=num[r];
				cha-=2*num[r];
				r--;
			}else if(num[l]<num[r]){
				num[r]-=num[l];
				cha-=2*num[l];
				l++;
			}else{
				cha-=2*num[l];
				l++;
				r--;
			}
		}
	}
	cout<<sum;
	return 0;
}
