#include<bits/stdc++.h>
using namespace std;
long long a[1000000];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long c,t,n,d,ans1=0,ans2=0,sum=0,x,i;
	cin>>c>>t;
	while(t){
		cin>>n>>d;
		i=1;
		ans1=ans2=0; 
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		while(i<n){
			if(i+d<=n){
				i+=d;
				ans1+=d;
			}else if(i+1<=n){
				i+=1;
				ans1+=1;
			}
		}
		i=1;
		while(i<n){
			if(i+1<=n){
				i+=1;
				ans2+=1;
			}else if(i+d<=n){
				i+=d;
				ans2+=d;
			}
		}
		if(ans1==ans2){
			sum++;
		}
		cout<<sum<<endl;
		t--;
	}

	return 0;
}
