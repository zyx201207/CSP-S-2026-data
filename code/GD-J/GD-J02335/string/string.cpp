#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen
	int q[200001]={};
	char w[200001]={};
	int a,c=0;
	cin>>a;
	for(int i=1;i<=a;i++){
		cin>>q[i]>>w[i];
		c+=q[i]; 
	}
	int j=0;
	for(int i=1;i<=a;i++){
		if(i<a){
			while(w[i]==w[a]){
				if(q[i]>=q[a]){
					j=j+q[a]*2;
					q[i]-=q[a];
					a-=1;
				}
				else if(q[i]<q[a]){
					j=j+q[i]*2;
					q[a]-=q[i];
					q[i]=0;
					break;
				}
			}
			while(!(w[i]==w[a])){
				if(q[i]>=q[a]){
					q[i]-=q[a];
					a-=1;
				}
				else{
					q[a]-=q[i];
					q[i]=0;
					break;
				}
			}
		}
		else{
			j+=q[i];
		}
	}
	int ans=0;
	ans=(c-j)/2;
	cout<<ans;
	
}
