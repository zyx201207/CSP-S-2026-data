#include <bits/stdc++.h>
using namespace std;
long long n,x,sum;
long long a[200005];
char c[200005];
bool flag=true,x2=true;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	scanf("%lld",&n);
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
		if(a[i]!=a[i-1]){
			flag=false;
		}
		if(c[i]!=c[i-1]){
			x2=false;
		}
		x+=a[i];
	}
	if(x2){
		cout<<"0";
		return 0;
	}else{
		string s;
		int l=0;
		if(flag){
			x/=a[1];
			for(int i=0;i<x;i++){
				s[l]=c[i];
				l++;
			}
		}else{
			for(int i=0;i<n;i++){
			    for(int j=0;j<a[i];j++){
					s[l]=c[i];
					l++;
				}
			}
		}
		int i=0,j=x-1;
		while(i!=x/2 and j!=x/2-1){
			if(s[i]!=s[j]){
				sum++;
			}
			i++;
			j--;
		}
		if(flag){
			if(x%2==0){
				printf("%lld",sum);
			}else{
				printf("%lld",2*sum);
			}
		}else{
			printf("%lld",sum);
		}
	}
	
	return 0;
} 
