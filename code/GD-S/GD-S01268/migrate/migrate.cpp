#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,x[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int z=1;z<=t;z++){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i];
		queue<int> he;
		for(int i=1;i<=n-3;i++){
			if(x[i+3]-x[i]>d && x[i+2]-x[i]<=d && x[i+3]-x[i+1]<=d && (i==n-3 || (x[i+4]-x[i+2]<=d)==(x[i+4]-x[i+1]<=d))){
				he.push(i+3);
			}
		} 
		int sum=0;
		for(int i=1;i<=n;i++){
			while(!he.empty() && x[i]>x[he.front()]-3){
				he.pop();
			}
			if(he.empty()) break;
			sum++;
			for(int i=he.front();i<=n-1;i++){
				if(x[i+1]-x[i]>d){
					break;
				}
				sum++;
			}
		}
		cout<<sum<<endl;
	}
	return 0;
} //RP++
