#include<bits/stdc++.h>
using namespace std;
int main(){
//	freopen("travel.in","r","stdin");
//	freopen("travel.out","w","stdout");
	stack<int>st1;
	int n,m,z,len=0,t=0,a[300010],b[300010];
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		if(i==1){
			st1.push(x);
			a[i]=x;
			b[x]++; 
		}
		else{
			for(int j=1;j<i;j++){
				if(a[j]==x){
					t=j;
					len=i-j;
					break;
				}
			}
			while(len--){
				st1.pop();
			}
			st1.push(x);
			for(int l=1;l<=i;l++){
				a[l]=0;
			}
			while(!st1.empty()){
				int t1=st1.top();
				st1.pop();
				a[z]=t1;
				b[t1]++;
				z++;
			}
			for(int h=1;h<=z;h++){
				st1.push(a[h]);
			}
			len=0,z=1,t=0;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	return 0;
	
} 
