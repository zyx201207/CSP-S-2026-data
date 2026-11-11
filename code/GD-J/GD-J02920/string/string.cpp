#include<bits/stdc++.h>
using namespace std;
#define int long long
char a[10000005];
string s;
int ans,n,b[10000005],x,y;
main(){
	freopen("string.in","r",stdin);
	freopen("string.out","r",stdout); 
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>b[i]>>a[i];
	} 
	int i=1,j=n;
	while(i<=n&&j>=1){
		x=b[i],y=b[j];
		if(a[i]!=a[j]){
			if(x>y){
				ans+=y;
				a[j]=a[i];
				b[j]=0;
				b[i]=x-y;
				j--;
			}else if(x<y){
				ans+=x;
				a[i]=a[j];
				b[j]=y-x;
				b[i]=0;
				i++;
			}else{
				ans+=x;
				a[i]=a[j];
				b[i]=0;
				b[j]=0;
				i++,j--;
			}
		}else{
			if(x>y){
				b[j]=0;
				b[i]=x-y;
				j--;
			}else if(x<y){
				b[j]=y-x;
				b[i]=0;
				i++;
			}else{
				b[i]=0;
				b[j]=0;
				i++,j--;
			}
		}
	}
	cout<<ans;
}
