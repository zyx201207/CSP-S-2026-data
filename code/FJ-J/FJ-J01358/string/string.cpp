#include <bits/stdc++.h>
using  namespace  std;
struct T{
	long long  a;
	char  b;
};
int  main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int  n,m=1;
	long long  sum=0;
	cin>>n;
	T  arr[n+1];
	int  s=n;
	for(int  i=1;i<=n;i++){
		long long  x;
		char  y;
		cin>>x>>y;
		if(i==1){
			arr[m].a=x;
			arr[m].b=y;
		}else{
			if(arr[m].b==y){
				s--;
				arr[m].a+=x;
			}else{
				m++;
				arr[m].a=x;
				arr[m].b=y;
			}
		}
	}
	int  x=s;
	for(int  i=1;i<=s/2;){	
		if(arr[i].b!=arr[x].b){
			if(arr[i].a==arr[x].a){
				sum+=arr[x].a;
				x--; 
				i++;
			}else  if(arr[i].a>arr[x].a){
				sum+=arr[x].a;
				arr[i].a-=arr[x].a;
				x--;
			}else{
				sum+=arr[i].a;
				arr[x].a-=arr[i].a;
				i++;
			}
		}else  if(arr[i].b==arr[x].b&&arr[i].a!=arr[x].a){
			if(arr[i].a>arr[x].a){
				arr[i].a-arr[x].a;
				x++;
			}else{
				arr[x].a-arr[i].a;
				i++;
			}
		}else{
			x++;
			i++;
		}
	}
	cout<<sum<<endl;
	return  0;
} 
