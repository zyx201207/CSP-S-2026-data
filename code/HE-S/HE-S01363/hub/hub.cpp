#include<bits/stdc++.h>
using namespace std;
int c,t;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout); 
	cin>>c>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		int u[114514],v[114514],sum=0;
		for(int i=1;i<=n-1;i++){
			cin>>u[i]>>v[i];
			if(i%2==1){
				sum+=u[i]+v[i];
			}else{
				sum-=v[i]-u[i];
			}
		}
		cout<<sum<<endl;
	}
}
/*5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 19*/ 
