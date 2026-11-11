#include<bits/stdc++.h>
using namespace std;
struct hui{
   char a;
   long long b;
}arr[200000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	char a;
	long long b,cnt=0;
	scanf("%lld",&n);
	for(int i=0;i<n;i++){
		cin>>b>>a;
		arr[i].a=a;
		arr[i].b=b;
	}
	int l=0,r=n-1;
	while(l<=r){
		if(l==r){
			break;
		}
		if(arr[l].a==arr[r].a){
			if(arr[l].b>arr[r].b){
				arr[l].b=abs(arr[l].b-arr[r].b);
				r--;
			}
			else if(arr[l].b<arr[r].b){
				arr[r].b=abs(arr[l].b-arr[r].b);
				l++;
		    }
		    else{
			    l++;r--;
			}
		}
		else{
			if(arr[l].b>arr[r].b){
				cnt+=arr[r].b;
				arr[l].b=abs(arr[l].b-arr[r].b);
				r--;
			}
			else if(arr[l].b<arr[r].b){
		        cnt+=arr[l].b;
				arr[r].b=abs(arr[l].b-arr[r].b);
				l++;
		    }
		    else{
				cnt+=arr[r].b;
			    l++;r--;
			}
		}
	}
	printf("%lld",cnt);
return 0;
}
