#include<bits/stdc++.h>
using namespace std;

int c,t;
int a,b,arr[200010],ar[200010],ans=0;

int main(){
	
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);

	scanf("%d%d",&c,&t);

	while(t--){

		a=0;
		b=0;
		ans=0;
		cin>>a>>b;
		for(int i=1;i<=a;i++){
			cin>>arr[i];
		}
		for(int i=a;i>1;i--){
			if(b%2==0)
			ar[i]=arr[i]-arr[1];
			else
			ar[i]=arr[i]-arr[i-1];
		}

		for(int i=a;i>1;i--){
			if(ar[i]%2==0&&ar[i]<=b){
				ans+=1;
			}
		}
		cout<<ans;
	}

	return 0;
}
