#include<bits/stdc++.h>
using namespace std;
int c,n,a,sum=0,min1=1e8;
bool z=0;
long long x[300000],d;
struct node{
	int a1,a2;
};
int y;
int main(){
//	freopen("migrate.in","r",stdin);
//	freopen("migrate.out","w",stdout);
	cin>>c>>n;
	for(int q=1;q<=n;q++){
		cin>>a>>d;
		for(int j=1;j<=a;j++){
			cin>>x[j];
		}
		for(int k1=1;k1<=a;k1++){
			for(int i=k1+4;i<=a;i++){
            queue <node> q;//นใหั 
			q.push({i,k1});
		      	while(!q.empty()){
				node u=q.front();
				for(int j=1;;j++){
					if(u.a1-j>=k1&&x[u.a1]-x[j]<=d&&u.a2<=min1){
						q.push({u.a1-j,u.a2+1});
						if(u.a1-j==k1&&u.a2+1<=min1){
					y++;
					min1=min(min1,u.a2+1);
					z=1;
				   }
					}
			
				}
				if(z==1){
					break;
				
			    }
				q.pop();
				}//
				
			if(y==2){
				sum++;
			
		}
		y=0;
			while(!q.empty()){
			q.pop();
		}
		z=0;
	}
		}
		cout<<sum<<endl;
		sum=0;
	}
	return 0;
}

