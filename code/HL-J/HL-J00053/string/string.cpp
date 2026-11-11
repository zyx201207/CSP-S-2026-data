#include<bits/stdc++.h>
using namespace std;
int q[200007],s=0;
char z[200007];
int main(){
	freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
	long long n,t,w,i=1;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>q[i]>>z[i];
	}
	t=1;w=n;
	while(t!=w){
		if(z[t]==z[w]){
			if(q[t]>=q[w]){
				q[t]-=q[w];
				q[w]=0;
			}
			else{
				q[w]-=q[t];
				q[t]=0;
			}
		}
		else{
			if(q[t]>=q[w]){
				q[t]-=q[w];
				s+=q[w];
				q[w]=0;
			}
			else{
				q[w]-=q[t];
				s+=q[t];
				q[t]=0;
			}
		}
		if(q[t]==0){
			t++;
		}
		if(q[w]==0){
			w--;
		}
	}
	cout<<s;
	return 0;
}