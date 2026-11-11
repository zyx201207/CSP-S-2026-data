#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,a[2000005],t=0;
	char c[2000005];
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
	}
	long long x=a[0],y=a[n-1];
	long long i1=0,j1=n-1;
	while(i1<j1){
		if(c[i1]!=c[j1]){
			t+=min(x,y);
			if(x>y){j1--;
				x-=y;y=a[j1];
			}else{
				i1++;
				y-=x;x=a[i1];
			}
		}else{
			if(x>y){j1--;
				x-=y;y=a[j1];
			}else{
				i1++;
				y-=x;x=a[i1];
			}
		}
	}
	cout<<t;
	fclose(stdin);fclose(stdout);
	return 0;
} 
