#include<bits/stdc++.h> 
using namespace std;
long long n,sum,x[200005],ans;
char a[200005];
int main(){
	freopen("string.in","r","stdin");
	freopen("string.out","w","stdout");
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x[i];
		sum+=x[i];
		cin>>a[i];
		
	}
	long long i=1,y=1;
	while(i<=n/2){
		if(a[i]==a[n+1-y]&&x[i]==x[n+1-y]){
			i++;
			y++;
			//continue;
		}
		else if(a[i]==a[n+1-y]&&x[i]<x[n+1-y]){
			x[n+1-y]-=x[i];
			i++;
			//continue;
		}
		else if(a[i]==a[n+1-y]&&x[i]>x[n+1-y]) {
			x[i]-=x[n+1-y];
			i++;
			//continue;
		}
		if(a[i]!=a[n+1-y]){
			if(x[i]==x[n+1-y]){
				ans+=x[i];
				i++;
				y++;
				//continue;
			}
			else if(x[i]>x[n+1-y]){
				ans+=x[i];
				i++;
				//continue;
			}
			else if(x[i]<x[n+1-y]){
				ans+=x[n+1-y];
				x[i]-=x[n+1-y];
				y++;
				//continue;
			}
			
		}
	}
	cout<<ans;
	return 0;
}
/*


*/
