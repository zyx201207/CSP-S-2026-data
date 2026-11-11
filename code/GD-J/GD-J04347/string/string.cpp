#include<bits/stdc++.h>
using namespace std;
int n;
char a[200005];
int b[200005];
long long ans=0,s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		scanf("%d %c",&b[i],&a[i]);
		s+=b[i];
	}
	for(int i=0,j=n-1;i<j;){
		long long x=b[i],y=b[j];
		if(a[i]!=a[j]){
			if(x<y){
				ans+=x;
				b[j]=y-x;
				i++;
			}else{
				ans+=y;
				b[i]=x-y;
				j--;
			}
		}else{
			if(x<y){
				b[j]=y-x;
				i++;
			}else{
				b[i]=x-y;
				j--;
			}
		}
	}
	cout<<ans;
	return 0;
}

