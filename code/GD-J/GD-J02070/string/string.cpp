#include<iostream>

using namespace std;

long long a[200010],b[200010];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	char x;
	cin >>n;
	for(long long i=1;i<=n;i++){
		cin >>a[i]>>x;
		b[i]=x-'a';
	}
	long long first=1,end=n,ans=0;
	while(first <= end){
		if(a[first]<=0) first++;
		if(a[end]<=0) end--;
		if(b[first]!=b[end]){
			if(a[first]<=a[end]){
				ans+=a[first];
				if(a[end]-a[first]<0){
					end--;
				}else{
					a[end]-=a[first];	
				}
				end--;
			}else{
				ans+=a[end];
				if(a[first]-a[end]<0){
					first++;
				}else{
					a[first]-=a[end];	
				}
				first++;
			}
		}else{
			first++;
			end--;
		}
	}
	cout<<ans;
	return 0;
}
